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
    private int[] nums;
​
    /* Recursively finding the middle of the subarray as the root of the subtree. */
    public TreeNode sortedArrayToBST(final int[] nums) {
        this.nums = nums;
        return buildBalancedBSTSubtree(0, nums.length);
    }
​
    private TreeNode buildBalancedBSTSubtree(final int beginIndex, final int endIndex) {
        if (endIndex <= beginIndex) {
            return null;
        }
        /* NOTE: using greater middle may cause boundry issues */
        final int middleIndex = getSmallerMiddleIndex(beginIndex, endIndex);
        final TreeNode root = new TreeNode(nums[middleIndex]);
        root.left = buildBalancedBSTSubtree(beginIndex, middleIndex);
        root.right = buildBalancedBSTSubtree(middleIndex + 1 /* exclude root */, endIndex);
        return root;
    }
​
    private static int getSmallerMiddleIndex(final int beginIndex, final int endIndex) {
        return (beginIndex + endIndex) / 2;
    }
}
​
