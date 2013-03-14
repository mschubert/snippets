#!/usr/bin/env python2

import sys, os
from PySide import QtCore, QtGui

from PySide.QtCore import *
from PySide.QtGui import *


class _Zoomed(QWidget):
    def __init__(self, parent=None):
        self.parent = parent
        QWidget.__init__(self, parent)

    def wheelEvent(self, event):
        self.parent.wheelEvent(event)


class Zoomable(QWidget):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)

        self.zoomed = _Zoomed(self)
        self.zoomed.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Ignored)
        self.size = QSize(500, 400)

        self.scrollArea = QtGui.QScrollArea(self)
        self.scrollArea.setWidget(self.zoomed)
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setFixedSize(self.size)

        self.resize(self.size);
        self.scale = 1.0

    def scaleWidget(self, factor):
        self.scale *= factor;
        if self.scale > 3:
            self.scale = 3
        elif self.scale > 1:
            self.scrollArea.horizontalScrollBar().show()
            self.scrollArea.verticalScrollBar().show()
        else:
            self.scale = 1
            self.scrollArea.horizontalScrollBar().hide()
            self.scrollArea.verticalScrollBar().hide()

        self.zoomed.setFixedSize(self.scale * self.size)
        self.adjustScrollBar(self.scrollArea.horizontalScrollBar(), factor);
        self.adjustScrollBar(self.scrollArea.verticalScrollBar(), factor);

    def adjustScrollBar(self, scrollBar, factor):
        scrollBar.setValue(int(factor * scrollBar.value() \
            + ((factor - 1) * scrollBar.pageStep()/2)))

    def wheelEvent(self, event):
        event.accept()
        factor = 1.41 ** (event.delta() / 240.0)
        self.scaleWidget(factor)

        x, y = event.pos().x(), event.pos().y()
        xmargin, ymargin = self.size.width()/2, self.size.height()/2
        self.scrollArea.ensureVisible(x, y, xmargin, ymargin)


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    window = Zoomable()
    window.show()
    sys.exit(app.exec_())

