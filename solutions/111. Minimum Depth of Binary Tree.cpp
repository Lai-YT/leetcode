/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    std::queue<TreeNode *> level_nodes{};
    level_nodes.push(root);
    int depth = 0;
    while (!level_nodes.empty()) {
      ++depth;
      size_t num_of_nodes_in_curr_level = level_nodes.size();
      for (size_t i = 0; i < num_of_nodes_in_curr_level; ++i) {
        TreeNode *curr = level_nodes.front();
        level_nodes.pop();
        if (IsLeaf_(curr)) {
          return depth;
        }
        if (curr->left) {
          level_nodes.push(curr->left);
        }
        if (curr->right) {
          level_nodes.push(curr->right);
        }
      }
    }
    assert(0);  // should not get here
  }

 private:
  bool IsLeaf_(TreeNode *node) { return !node->left && !node->right; }
};
