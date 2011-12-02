#!/usr/bin/env python
#
# QtMacro is a PyQT frontent to the command-line tool xmacro.
# - written by Michael Schubert, EMBL-EBI, 2011
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
"""
Graphical User Interface for the xmacrorec2 and xmacroplay command-line
tools. To use:
  - Press the "Record" button
  - Press any key (Escape is a good choice usually) to start and stop the actual recording
  - Choose speed and number of repetitions, and press "Play" to replay the macro
"""

import sys, subprocess
from os import remove
from PyQt4 import QtCore, QtGui


class QtMacro(QtGui.QWidget):
    """
    Class to draw the GUI and handle its events. Paths to the command-line tools
    xmacrorec2 and xmacroplay are also specified here.
    """
    def __init__(self):
        super(QtMacro, self).__init__()
        self.xmacrorec = "xmacrorec2"
        self.xmacroplay = "xmacroplay"
        self.setupUi()
        
    def setupUi(self):
        self.setFixedSize(240,100)
        self.gridLayoutWidget = QtGui.QWidget(self)
        self.gridLayoutWidget.setGeometry(QtCore.QRect(5, 5, 235, 95))
        self.gridLayout = QtGui.QGridLayout(self.gridLayoutWidget)
        self.gridLayout.setMargin(0)
        self.record = QtGui.QPushButton(self.gridLayoutWidget)
        self.play = QtGui.QPushButton(self.gridLayoutWidget)
        self.reset = QtGui.QPushButton(self.gridLayoutWidget)
        self.repeat = QtGui.QSpinBox(self.gridLayoutWidget)
        self.repeat.setMinimum(1)
        self.repeat.setMaximum(100)
        self.label_speed = QtGui.QLabel(self.gridLayoutWidget)
        self.label_repeat = QtGui.QLabel(self.gridLayoutWidget)
        self.hint = QtGui.QLabel(self.gridLayoutWidget)
        
        self.speed = QtGui.QComboBox(self.gridLayoutWidget)
        for i in range(4):
            self.speed.addItem("")
        
        self.gridLayout.addWidget(self.record, 0, 0, 1, 1)
        self.gridLayout.addWidget(self.play, 1, 0, 1, 1)
        self.gridLayout.addWidget(self.reset, 2, 0, 1, 1)
        self.gridLayout.addWidget(self.hint, 0, 1, 1, 2)
        self.gridLayout.addWidget(self.speed, 1, 1, 1, 1)
        self.gridLayout.addWidget(self.repeat, 2, 1, 1, 1)
        self.gridLayout.addWidget(self.label_speed, 1, 2, 1, 1)
        self.gridLayout.addWidget(self.label_repeat, 2, 2, 1, 1)
        
        self.cursor = QtGui.QCursor()
        self.retranslateUi()
        QtCore.QObject.connect(self.record, QtCore.SIGNAL('clicked()'), self.onRecord)
        QtCore.QObject.connect(self.play, QtCore.SIGNAL('clicked()'), self.onPlay)
        QtCore.QObject.connect(self.reset, QtCore.SIGNAL('clicked()'), self.onReset)

    def retranslateUi(self):
        self.setWindowTitle("QtMacro")
        self.record.setText("&Record")
        self.reset.setText("Re&set")
        self.play.setText("Play")
        self.label_speed.setText("x speed")
        self.label_repeat.setText("x repeat")
        self.hint.setText("Press Record")
        for i, speed in enumerate(["1", "5", "10", "100"]):
            self.speed.setItemText(i, speed)
        self.record.setEnabled(True)
        self.play.setEnabled(False)
        self.speed.setEnabled(False)
        self.repeat.setEnabled(False)
        
    def onRecord(self):
        self.hint.setText("Same key to start/end")
        self.record.setEnabled(False)
        self.worker = Worker(self, self.xmacrorec)
        QtCore.QObject.connect(self.worker, QtCore.SIGNAL('done(QString)'), self.onStopRecording)
        self.worker.start()
        
    def onStopRecording(self, output):
        self.hint.setText("Macro recorded")
        self.play.setEnabled(True)
        self.speed.setEnabled(True)
        self.repeat.setEnabled(True)
        self.macro = output
        
    def onPlay(self):
        self.pos = self.cursor.pos()
        run = self.xmacroplay + " --speed " + str(1/float(self.speed.itemText(self.speed.currentIndex())))
        self.worker = Worker(self, run, int(self.repeat.value()) * self.macro)
        QtCore.QObject.connect(self.worker, QtCore.SIGNAL('done(QString)'), self.onDone)
        self.worker.start()

    def onDone(self):
        self.cursor.setPos(self.pos)
        self.setFocus()

    def onReset(self):
        self.retranslateUi()


class Worker(QtCore.QThread):
    """
    Class that handles xmacro execution inside a thread
    """
    def __init__(self, parent, execute, istream=None):
        super(Worker, self).__init__()
        self.execute = execute
        if istream == None:
            self.istream = None
        else:
            self.istream = str(istream)

    def run(self):
        child = subprocess.Popen(self.execute,
                                 stdin=subprocess.PIPE,
                                 stdout=subprocess.PIPE,
                                 stderr=subprocess.PIPE,
                                 shell=True)
        out, err = child.communicate(self.istream)
        self.emit(QtCore.SIGNAL("done(QString)"), out.encode("ASCII"))


if __name__ == "__main__":
    """
    Start and show the application when called as a script
    """
    app = QtGui.QApplication(sys.argv)
    gui = QtMacro()
    gui.show()
    app.exec_()
    try:
        remove("xmacro.ini")
    except:
        pass