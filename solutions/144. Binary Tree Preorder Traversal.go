/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
	vals := make([]int, 0)
	recursivePreorderTraversal(root, &vals)
	return vals
}

func recursivePreorderTraversal(root *TreeNode, vals *[]int) {
	if root == nil {
		return
	}
	*vals = append(*vals, root.Val)
	recursivePreorderTraversal(root.Left, vals)
	recursivePreorderTraversal(root.Right, vals)
}
