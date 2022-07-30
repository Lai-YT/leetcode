/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/
​
class Solution {
    /**
     * {@summary}
     * When we visit a node, we clone it and its neighbors,
     * while the neighbor of neighbors aren't.
     * So neighbors are put into the queue,
     * we'll visit the neighbor of neighbors in the next loop.
     * @param node the root node of the graph to be cloned
     * @return the root node of the copy
     */
    public Node cloneGraph(Node node) {
        if (node == null) {
            return null;
        }
​
        /* The cloned nodes lives inside. */
        HashMap<Integer /* val */, Node> cloned = new HashMap<>();
        /* Queue and Stack are both okay. */
        Stack<Node> toClones = new Stack<>();
​
        cloned.put(node.val, new Node(node.val));
​
        toClones.push(node);
        while (!toClones.isEmpty()) {
            Node curr = toClones.pop();
            Node copy = cloned.get(curr.val);
            for (Node neighbor : curr.neighbors) {
                if (!cloned.containsKey(neighbor.val)) {
                    cloned.put(neighbor.val, new Node(neighbor.val));
                    /* Visit the neighbor of neighbors in the next loop. */
                    toClones.push(neighbor);
                }
                copy.neighbors.add(cloned.get(neighbor.val));
            }
        }
        return cloned.get(node.val);
    }
}
​
