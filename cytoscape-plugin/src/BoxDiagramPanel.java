package NetworkFailurePackage;

import java.awt.Color;
import java.awt.Graphics;

/*
 * BoxDiagramPanel.java
 *
 * Created on 15.02.2011, 16:37:32
 */

/**
 * Class to draw the box plots that represent the number of failure nodes with
 * the specified amount of nodes removed from the network.
 *
 * @author Michael Schubert
 */
public class BoxDiagramPanel extends javax.swing.JPanel {
    /**
     * Unused constructor, no components to initialise.
     */
    public void BoxDiagramPanel() {
    }

    /**
     * Used to set node failure data as class property.
     *
     * @param data The node failure average with 0 to data.length nodes removed.
     */
    public void setData(float[] data) {
        this.data = data;
    }

    private float data[] = null;            // number of failure nodes in each run
    private final int xpaddingLeft = 10;    // the padding between left widget border and the plot
    private final int xpaddingRight = 30;   // the padding between right widget border and the plot
    private final int ybase = 249;          // the y-coordinates of the plot baseline
    private final int maxHeight = ybase-30; // the maximum height of boxes in the widget

    /**
     * Called every time the panel is painted or re-painted. Does nothing when no failure
     * node data is present. If it is, it calculates the number of boxes that will be
     * used to plot the diagram, their width and the scaling paramter {@link maxAvg} so that
     * each box occupies the relative amount of failure nodes in widget space. Also
     * clears the canvas by painting the whole widget in background-colour and calls the
     * methods for {@link drawLineLabels()} and {@link drawBoxes()}.
     *
     * @param g The graphics handler that is used to draw on the panel
     */
    @Override public void paint(Graphics g) {
        if (data == null) {
            return;
        }
        // get some descriptive data
        int nBoxes = data.length;
        int boxWidth = (getWidth()-xpaddingLeft-xpaddingRight) / nBoxes;
        float maxAvg = 0;
        for(int i=0; i<nBoxes; i++) {
            if (data[i] > maxAvg) {
                maxAvg = (int)data[i];
            }
        }

        // clear canvas
        g.setColor(getBackground());
        g.fillRect(0, 0, getWidth(), getHeight());
        // draw the box diagram and labels
        drawLineLabels(g, maxAvg);
        for(int i=0; i<nBoxes; i++) {
            drawBox(g, i, boxWidth, data[i], maxAvg);
        }
    }

    /**
     * Draws a legend, labels, and hinting lines on the diagram. This is done before the
     * actual boxes are drawn so that it does not obstruct the visual data. The labels
     * of the Y-axis include marks to 0 failure nodes, as well as a medium and a high
     * integer amount. On each mark, a line is drawn from left to right on the diagram
     * in order to make it more readable. X-axis labelling is mainly done in the
     * {@link drawBox()} method. The axes are labelled as FN (failure nodes) and NR (nodes
     * removed), respectively.
     *
     * @param g The graphics handler that is used to draw on the panel
     * @param maxAvg The maximum average value of failure node amount for scaling purposes
     */
    private void drawLineLabels(Graphics g, float maxAvg) {
        // calculate hint line positions
        double top = Math.floor(maxAvg);
        int ytop = ybase-(int)(maxHeight * (top/maxAvg));
        double mid = Math.floor(maxAvg/2);
        int ymid = ybase-(int)(maxHeight * (mid/maxAvg));
        // draw axis labels
        g.setColor(Color.black);
        g.drawString("FN", getWidth()-xpaddingRight/2-10, ybase-maxHeight-15);
        g.drawString("NR", xpaddingLeft-7, ybase+15);
        g.drawString("0", getWidth()-xpaddingRight/2-7, ybase+4);
        // draw hint line labels
        g.drawString(((Integer)(int)mid).toString(), getWidth()-xpaddingRight/2-7, ymid+4);
        g.drawString(((Integer)(int)top).toString(), getWidth()-xpaddingRight/2-7, ytop+4);
        // draw hint lines
        g.setColor(Color.lightGray);
        g.drawLine(xpaddingLeft-5, ybase, getWidth()-xpaddingRight+5, ybase);
        g.drawLine(xpaddingLeft-5, ytop, getWidth()-xpaddingRight+5, ytop);
        g.drawLine(xpaddingLeft-5, ymid, getWidth()-xpaddingRight+5, ymid);
    }

    /**
     * Used to draw an individual box from the average of one failure-node determining 
     * run. The box consists of a filled shape and a gray border. Beneath it is labelled with
     * a number that indicates how many nodes were removed in that run.
     *
     * @param g The graphics handler that is used to draw on the panel.
     * @param boxN The number of the current box. This is used for placement and the box label.
     * @param width The width of a single box.
     * @param avg The average number of failure nodes that is represented by the current box.
     * @param maxAvg The maximum average value of failure node amount for scaling purposes.
     */
    private void drawBox(Graphics g, int boxN, int width, float avg, float maxAvg) {
        // draw box, make sure it is not bigger as panel
        int height = (int)(maxHeight * (avg/maxAvg));
        if (height > ybase) {
            height = ybase;
        }
        g.setColor(Color.green);
        g.fillRect(xpaddingLeft + boxN*width, ybase-height, width, height);
        g.setColor(Color.gray);
        g.drawRect(xpaddingLeft + boxN*width, ybase-height, width, height);
        // draw box label
        g.setColor(Color.black);
        g.drawString(((Integer)boxN).toString(), xpaddingLeft+boxN*width+width/2-2, ybase+15);
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 300, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents

    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
