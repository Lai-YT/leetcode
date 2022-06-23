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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        std::queue<TreeNode *> level_nodes{};
        level_nodes.push(root);
        int depth = 0;
        while (!level_nodes.empty()) {
            ++depth;
            size_t curr_level_number_of_nodes = level_nodes.size();
            for (size_t i = 0; i < curr_level_number_of_nodes; ++i) {
                TreeNode* curr = level_nodes.front();
                level_nodes.pop();
                bool is_leaf = true;
                if (curr->left) {
                    level_nodes.push(curr->left);
                    is_leaf = false;
                }
                if (curr->right) {
                    level_nodes.push(curr->right);
                    is_leaf = false;
                }
                if (is_leaf) {
                    return depth;
                }
            }
        }
        return depth;
    }
};
