# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        return_list: List[int] = list()
        stack: List[TreeNode] = list()
        curr: TreeNode = root
        while True:
            if curr:
                stack.append(curr)
                curr = curr.left
            elif len(stack):
                curr = stack.pop()
                return_list.append(curr.val)
                curr = curr.right
            else:
                break
        return return_list
        
        
