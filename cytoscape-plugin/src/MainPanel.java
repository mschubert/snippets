package NetworkFailurePackage;

import giny.model.Node;
import java.util.ArrayList;
import javax.swing.JOptionPane;

/*
 * PluginGUI.java
 *
 * Created on 12.02.2011, 15:57:21
 */

/**
 * Class to hold the main panel of the plugin. For the most part, designed using the
 * form designer of NetBeans. Also contains logic to handle the two button press events.
 *
 * @author Michael Schubert
 */
public class MainPanel extends javax.swing.JPanel {
    /**
     * Constructor of the MainPanel class. Used to set a reference property for the main
     * plugin class and to initialise the panel components designed with the form editor.
     *
     * @param plugin Reference to the main plugin class, saved as a class property here.
     * @param nNodes The number of nodes in the current network.
     * @param nEdges The number of edges in the current network.
     */
    public MainPanel(NetworkFailurePlugin plugin, int nNodes, int nEdges) {
        // set the properties
        this.plugin = plugin;
        maxRemoveNodes = nNodes/2;
        if (maxRemoveNodes > 10) {
            maxRemoveNodes = 10;
        }
        initComponents();
        // make sure default node removal maximum is supported
        if (Integer.parseInt(maxNodes.getText()) > maxRemoveNodes) {
            maxNodes.setText(((Integer)maxRemoveNodes).toString());
        }
        // print out some basic statistics about the whole network
        float edgesPerNode = (float)((int)((float)100*nEdges/nNodes)) / 100;
        heading.setText("<html><b>Network Failure Plugin</b> - " + nNodes + " nodes loaded "
                + " with an average connectivity of " + edgesPerNode + "</html>");
    }

    /**
     * Reference to the main plugin class in order to call the application logic
     * to calculate the failure nodes and have the results delivered here. It is
     * set in the constructor.
     */
    private NetworkFailurePlugin plugin;

    /**
     * The maximum number of nodes to remove when plotting.
     */
    private int maxRemoveNodes;

    /**
     * This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        doIdentify = new javax.swing.JButton();
        heading = new javax.swing.JLabel();
        headingSeparator = new javax.swing.JSeparator();
        doPlot = new javax.swing.JButton();
        maxNodes_desc = new javax.swing.JLabel();
        maxNodes = new javax.swing.JTextField();
        nRuns_desc = new javax.swing.JLabel();
        nRuns = new javax.swing.JTextField();
        scrollPane = new javax.swing.JScrollPane();
        nodeListContent = new javax.swing.DefaultListModel();
        nodeListContent.addElement("<empty>");
        nodeList = new javax.swing.JList();
        boxDiagram = new NetworkFailurePackage.BoxDiagramPanel();

        doIdentify.setText("<html><center>Find and select failure nodes in network</center></html>");
        doIdentify.setActionCommand("Identify failure \\npoints");
        doIdentify.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                doIdentifyActionPerformed(evt);
            }
        });

        heading.setText("placeholder");

        doPlot.setText("<html><center>Plot node removal vs failure nodes</center></html>");
        doPlot.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                doPlotActionPerformed(evt);
            }
        });

        maxNodes_desc.setText("Max nodes to remove");

        maxNodes.setText("5");

        nRuns_desc.setText("Average over runs");

        nRuns.setText("10");

        nodeList.setModel(nodeListContent);
        scrollPane.setViewportView(nodeList);

        boxDiagram.setPreferredSize(new java.awt.Dimension(346, 289));

        javax.swing.GroupLayout boxDiagramLayout = new javax.swing.GroupLayout(boxDiagram);
        boxDiagram.setLayout(boxDiagramLayout);
        boxDiagramLayout.setHorizontalGroup(
            boxDiagramLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 346, Short.MAX_VALUE)
        );
        boxDiagramLayout.setVerticalGroup(
            boxDiagramLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 265, Short.MAX_VALUE)
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(headingSeparator, javax.swing.GroupLayout.DEFAULT_SIZE, 541, Short.MAX_VALUE)
                    .addComponent(heading)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(6, 6, 6)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(scrollPane, javax.swing.GroupLayout.DEFAULT_SIZE, 177, Short.MAX_VALUE)
                            .addComponent(doIdentify, javax.swing.GroupLayout.DEFAULT_SIZE, 177, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(doPlot, javax.swing.GroupLayout.DEFAULT_SIZE, 168, Short.MAX_VALUE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(maxNodes_desc)
                                    .addComponent(nRuns_desc))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                    .addComponent(nRuns)
                                    .addComponent(maxNodes)))
                            .addComponent(boxDiagram, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(heading)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(headingSeparator, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(doIdentify, javax.swing.GroupLayout.PREFERRED_SIZE, 46, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(doPlot, javax.swing.GroupLayout.PREFERRED_SIZE, 46, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(maxNodes_desc)
                            .addComponent(maxNodes, javax.swing.GroupLayout.PREFERRED_SIZE, 21, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(nRuns, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(nRuns_desc))))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(scrollPane, javax.swing.GroupLayout.DEFAULT_SIZE, 265, Short.MAX_VALUE)
                    .addComponent(boxDiagram, javax.swing.GroupLayout.DEFAULT_SIZE, 265, Short.MAX_VALUE))
                .addContainerGap())
        );
    }// </editor-fold>//GEN-END:initComponents

    /**
     * Clears the failure node list on the left of the main panel and re-fills it
     * the the names of nodes that were determined to be failure nodes in the last
     * calulation. Also prints out some basic statistics about the failure nodes
     * in the panel header and selects the found nodes in the network view.
     *
     * @param evt The button press event. It is used solely to call this method.
     */
    private void doIdentifyActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_doIdentifyActionPerformed
        // unselect all and clear failure node list
        nodeListContent.clear();
        plugin.net.unselectAllNodes();
        int failureNodes[] = plugin.getFailureNodes(new ArrayList<Integer>());
        float failureNodeEdgesN = 0;
        // for each failure node: put in list and select in network
        for (int i: failureNodes) {
            Node node = plugin.net.getNode(i);
            plugin.net.setSelectedNodeState(node, true);
            nodeListContent.addElement(node.getIdentifier());
            failureNodeEdgesN += plugin.net.getInDegree(node) + plugin.net.getOutDegree(node);
        }
        plugin.netView.updateView();
        // print out some basic statistics about the failure nodes
        float edgesPerFailureNode = (float)((int)((float)100*failureNodeEdgesN/failureNodes.length)) / 100;
        heading.setText("<html><b>Network Failure Plugin</b> - found " + failureNodes.length +
                " failure nodes with an average connectivity of " + edgesPerFailureNode + "</html>");
    }//GEN-LAST:event_doIdentifyActionPerformed

    /**
     * Used to sanitise text field input from the user and then calculate the average
     * number of failure nodes from each run of the {@link getFailureNodesWithRemoval()} method
     * and stores the result in an array that is then passed to the {@link BoxDiagramPanel}
     * class to be used to draw the box plots.
     *
     * @param evt The button press event. It is used solely to call this method.
     */
    private void doPlotActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_doPlotActionPerformed
        // make sure input fields are indeed integers
        int maxRemove=0, avgRuns=0;
        try {
            maxRemove = Integer.parseInt(maxNodes.getText());
            avgRuns = Integer.parseInt(nRuns.getText());
        }
        catch(Exception e) {
            final String msg = "Node number and iterations need to be integers";
            JOptionPane.showMessageDialog(this, msg, "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        // and max nodes to remove are not negative or too high
        if (maxRemove < 0 || maxRemove > maxRemoveNodes) {
            final String msg = "The number of nodes to remove needs to be between 0 and " +
                    maxRemoveNodes + " for this network";
            JOptionPane.showMessageDialog(this, msg, "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        // and do at least one run
        if (avgRuns < 1) {
            final String msg = "Need to do at least one run";
            JOptionPane.showMessageDialog(this, msg, "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        // get the average number of failure nodes found in each run...
        float data[] = new float[maxRemove+1];
        for (int remove=0; remove<=maxRemove; remove++) {
            int failureRemoval[] = plugin.getFailureNodesWithRemoval(remove, avgRuns);
            // calculate average number of failure nodes
            float sum = 0;
            for (int i=0; i<failureRemoval.length; i++) {
                sum += failureRemoval[i];
            }
            data[remove] = sum / failureRemoval.length;
        }
        // ...and pass it to the boxDiagram to draw
        boxDiagram.setData(data);
        boxDiagram.repaint();
    }//GEN-LAST:event_doPlotActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private NetworkFailurePackage.BoxDiagramPanel boxDiagram;
    private javax.swing.JButton doIdentify;
    private javax.swing.JButton doPlot;
    private javax.swing.JLabel heading;
    private javax.swing.JSeparator headingSeparator;
    private javax.swing.JTextField maxNodes;
    private javax.swing.JLabel maxNodes_desc;
    private javax.swing.JTextField nRuns;
    private javax.swing.JLabel nRuns_desc;
    private javax.swing.DefaultListModel nodeListContent;
    private javax.swing.JList nodeList;
    private javax.swing.JScrollPane scrollPane;
    // End of variables declaration//GEN-END:variables
}