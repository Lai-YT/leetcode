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
    bool dfs(TreeNode *n, int const & num) {
        if (!n) return true;
        if (n->val != num) return false;
        return dfs(n->left, num) && dfs(n->right, num);
    }
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        int const num = root->val;
        return dfs(root, num);
    }
};
