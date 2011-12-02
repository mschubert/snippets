package NetworkFailurePackage;

import cytoscape.CyNetwork;
import cytoscape.Cytoscape;
import cytoscape.plugin.CytoscapePlugin;
import cytoscape.util.CytoscapeAction;
import cytoscape.view.CyNetworkView;
import java.awt.event.ActionEvent;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import org.apache.commons.lang.ArrayUtils;

/*
 * NetworkFailurePlugin.java
 *
 * Created on 12.02.2011, 13:48:32
 */

/**
 * Main plugin class that contains most of the application logic. Roughly represents the
 * Controller in the MVC model (where the View are the panel classes and the model
 * resides within Cytoscape).
 * 
 * @author Michael Schubert
 */
public class NetworkFailurePlugin extends CytoscapePlugin {
    /**
     * Creates the menu entry class and initializes the random number generator.
     */
    public NetworkFailurePlugin() {
        PluginMenuAction menuAction = new PluginMenuAction(this);
	Cytoscape.getDesktop().getCyMenus().addCytoscapeAction((CytoscapeAction)menuAction);
        generator = new Random();
    }

    /**
     * Responsible for the menu entry of the plugin and the GUI creation
     * upon clicking the menu entry
     */
    public class PluginMenuAction extends CytoscapeAction {
        NetworkFailurePlugin myPlugin;

        /**
         * Sets the menu entry.
         *
         * @param plugin A reference to the main plugin class that contains the application logic.
         */
        public PluginMenuAction(NetworkFailurePlugin plugin) {
            super("Identify failure nodes");
            setPreferredMenu("Plugins");
            myPlugin = plugin;
        }

        /**
         * Reads the network structure from Cytoscape and creates an array with
         * node indices as well as the plugin GUI upon clicking on the menu 
         * entry. Performs sanity checks on the network data.
         *
         * @param actionEvent The unused click-event on the menu entry.
         */
        @Override public void actionPerformed(ActionEvent e) {
            // initialise network and node indices
            net = Cytoscape.getCurrentNetwork();
            netView = Cytoscape.getCurrentNetworkView();
            nodeIndices = net.getNodeIndicesArray();
            // create PluginGUI panel inside frame and display
            JFrame pluginFrame = new JFrame();
            JPanel pluginPanel = new MainPanel(myPlugin, nodeIndices.length, net.getEdgeCount());
            pluginFrame.setTitle("Network Failure Plugin");
            pluginFrame.add(pluginPanel);
            pluginFrame.pack();
            pluginFrame.setResizable(false);
            pluginFrame.setVisible(true);
            // check if netword contains nodes
            if (nodeIndices.length < 3) {
                final String msg = "No network loaded or netword contains under 3 nodes";
                JOptionPane.showMessageDialog(pluginFrame, msg, "Error", JOptionPane.ERROR_MESSAGE);
                pluginFrame.dispose();
                return;
            }
            // check if network is not already split
            boolean nodeReachable[] = new boolean[nodeIndices.length];
            iterateNetwork(0, nodeReachable);
            if (ArrayUtils.indexOf(nodeReachable, false) != -1) {
                final String msg = "Need a functional network to analyse, this one is already split.\n"
                        + "You may remove isolated subnetworks and re-run the plugin.";
                JOptionPane.showMessageDialog(pluginFrame, msg, "Error", JOptionPane.ERROR_MESSAGE);
                pluginFrame.dispose();
                return;
            }
        }
    }

    /**
     * A random number generator instance that is used to determine which nodes to
     * randomly remove.
     */
    private Random generator;
    /**
     * A reference to the Cytoscape network.
     */
    CyNetwork net;
    /**
     * A reference to the Cytoscape network view.
     */
    CyNetworkView netView;
    /**
     * An array of node indices. Used extensively to convert between node and
     * arry indices.
     */
    private int nodeIndices[];

    /**
     * Calculates the number of failure points with {@link removeN} randomly removed nodes
     * for {@link iterations} which are saved in an int array that is returned.
     *
     * @param removeN The number of nodes to randomly remove (i.e., mark as not transversible by the
     * {@link iterateNetwork()} method) from the network. It is ensured that these are never failure nodes.
     * @param iterations The number of times to repeat random node removal.
     * @return An array of size iterations filled with the number of failure nodes found when
     * {@link removeN} nodes were randomly removed.
     */
    public int[] getFailureNodesWithRemoval(int removeN, int iterations) {
        // array to save number of failure nodes in each run
        int failureNodeNumber[] = new int[iterations];

        // get average of #iterations for random node removal
        for (int i=0; i<iterations; i++) {
            // get array of failure nodes to know which not to randomly remove
            int failureNodes[] = getFailureNodes(new ArrayList<Integer>());
            // fill array with as many random node indices as should be removed
            ArrayList removeNodeIndices = new ArrayList<Integer>();
            while (removeNodeIndices.size() < removeN) {
                int random = generator.nextInt(nodeIndices.length);
                // only mark node for removal if not already marked and not essential
                if (!ArrayUtils.contains(failureNodes, a2nIdx(random)) &&
                        removeNodeIndices.indexOf(random) == -1) {
                    removeNodeIndices.add((Integer)random);
                    // update failure nodes with that node removed
                    failureNodes = getFailureNodes(removeNodeIndices);
                }
            }
            // add number of failure nodes in current iteration to failureNodeNumber array
            failureNodeNumber[i] = failureNodes.length;
        }
        return failureNodeNumber;
    }

    /**
     * Checks every node if it is essential for the network to be connected (i.e., the node is
     * a failure node). In each step, the network is prepared by setting all removed nodes
     * (incl. the one that is currently examined) to be iteration-path blocking and the iteration
     * is then started with a node that is known exist. All nodes that have their essentiality 
     * flag switched on are then added to an array that is returned.
     *
     * @param removeArrayIndices An ArrayList of Integers (indices of the {@link nodeIndices} array)
     * that should be considered as removed from the network, i.e. are not transversible
     * by {@link iterateNetwork()}. An empty list can also be supplied and means that no nodes
     * are removed.
     * @return An array of node indices that were determined to be failure points.
     */
    public int[] getFailureNodes(ArrayList<Integer> removeArrayIndices) {
        // array to capture whether node at nodeIndices[i] is essential or not
        boolean nodeEssential[] = new boolean[nodeIndices.length];
        
        // loop through nodes that are not removed with removeNodeIndices
        for (int curArrayIndex=0; curArrayIndex<nodeIndices.length; curArrayIndex++) {
            if (removeArrayIndices.contains((Integer)curArrayIndex)) {
                continue;
            }
            // set current and all nodes in removeNodeIndices to visited
            boolean nodeReachable[] = new boolean[nodeIndices.length];
            nodeReachable[curArrayIndex] = true;
            for (int arrayIdx: removeArrayIndices) {
                nodeReachable[arrayIdx] = true;
            }
            // start iteration at a non-visited node and check if all were reached
            iterateNetwork(ArrayUtils.indexOf(nodeReachable, false), nodeReachable);
            nodeEssential[curArrayIndex] = ArrayUtils.indexOf(nodeReachable, false) != -1;
        }

        // return array with node indices that are essential (=failure points)
        ArrayList failureNodes = new ArrayList<Integer>();
        for (int curArrayIndex=0; curArrayIndex<nodeEssential.length; curArrayIndex++) {
            if (nodeEssential[curArrayIndex] == true) {
                failureNodes.add(a2nIdx(curArrayIndex));
            }
        }
        return list2array(failureNodes);
    }

    /**
     * Called once using a starting node and then iterates through the rest of the network
     * recursively, visiting all the nodes that are connected to the one where the method started
     * via a valid path. Connections (edges) are always followed when they point downstream or
     * are undirected.
     *
     * @param curArrayIndex The element in {@link nodeIndices} where the recursive iteration is
     * currently at.
     * @param nodeReachable An array that holds true for nodes that were (1) already visited or
     * (2) marked to be deleted and false otherwise. Each array position corresponds to the same
     * position in {@link nodeIndices} and the node indices at nodeIndices[position].
     */
    private void iterateNetwork(int curArrayIndex, boolean[] nodeReachable) {
        // if the node is already visited abort, else mark visited now
        if (nodeReachable[curArrayIndex] == true) {
            return;
        }
        nodeReachable[curArrayIndex] = true;
        // get all nodes connected to current one and iterate recursively
        for (int edge: net.getAdjacentEdgeIndicesArray(a2nIdx(curArrayIndex), false, true, true)) {
            iterateNetwork(n2aIdx(net.getEdgeSourceIndex(edge)), nodeReachable);
            iterateNetwork(n2aIdx(net.getEdgeTargetIndex(edge)), nodeReachable);
        }
    }

    /**
     * Converts an ArrayList of integer objects to an array with int primitives.
     *
     * @param list the ArrayList
     * @return the int array
     */
    private int[] list2array(ArrayList<Integer> list) {
        return ArrayUtils.toPrimitive((Integer[])list.toArray(new Integer[list.size()]));
    }

    /**
     * Converts a node index to a nodeIndices array index.
     *
     * @param arrayIndex A given node index.
     * @return The corresponding array index.
     */
    private int n2aIdx(int nodeIndex) {
        return ArrayUtils.indexOf(nodeIndices, nodeIndex);
    }

    /**
     * Converts a nodeIndices array index to a node index.
     *
     * @param arrayIndex A given array index.
     * @return The corresponding node index.
     */
    private int a2nIdx(int arrayIndex) {
        return nodeIndices[arrayIndex];
    }
}
