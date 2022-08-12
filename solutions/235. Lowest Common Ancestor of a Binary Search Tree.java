/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
​
class Solution {
    private TreeNode curr;
    private TreeNode p;
    private TreeNode q;
​
    /**
     * Find the first node where they separates,
     * which will be O(logn) in time complexity and O(1) in space complexity.
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        curr = root;
        this.p = p;
        this.q = q;
        while (curr != null) {
            if (foundOne() || goSeparate()) {
                return curr;
            }
            curr = bothInLeftTree() ? curr.left : curr.right;
        }
        return null;
    }
​
    private boolean foundOne() {
        return p.val == curr.val || q.val == curr.val;
    }
​
    /* strictly separate, will be false even though found one */
    private boolean goSeparate() {
        return (p.val - curr.val) * (q.val - curr.val) < 0;
    }
​
    private boolean bothInLeftTree() {
        return p.val < curr.val && q.val < curr.val;
    }
​
}
​
