/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    auto result = std::vector<int>{};
    auto stack = std::stack<TreeNode*>{};
    TreeNode* curr = root;
    while (curr || !stack.empty()) {
      /* go left if possible */
      while (curr) {
        stack.push(curr);
        curr = curr->left;
      }
      /* leaf node, visit parent and turn to explore the right tree */
      curr = stack.top();
      stack.pop();
      result.push_back(curr->val);
      curr = curr->right;
    }
    return result;
  }
};
​
