/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private Queue<TreeNode> queue = new LinkedList<>();
​
    /**
     * This is a iterative approach.
     * For example, a tree has the following structure:
     *       1     --- level 1 (won't be offered)
     *     2   3   --- level 2
     *   4  5 6  7 --- level 3
     * nodes will be offered in the order of 2 3 4 7 5 6,
     * they are checked in a symmetric breadth-first fashion.
     */
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return false;
        }
        queue.offer(root.left);
        queue.offer(root.right);
        while (!queue.isEmpty()) {
            final TreeNode n = queue.poll();
            final TreeNode m = queue.poll();
            if (isBothNull(n, m)) {
                continue;
            }
            if (isEqualVal(n, m)) {
                queue.offer(n.left);
                queue.offer(m.right);
​
                queue.offer(n.right);
                queue.offer(m.left);
            } else {
                return false;
            }
        }
        return true;
    }
​
    private boolean isBothNull(final TreeNode n, final TreeNode m) {
        return n == null && m == null;
    }
​
    private boolean isEqualVal(final TreeNode n, final TreeNode m) {
        if (isBothNull(n, m)) {  // for logic complete, though we've already checked above
            return true;
        }
        if (n == null || m == null) {
            return false;
        }
        return n.val == m.val;
    }
}
​
