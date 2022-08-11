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
    bool isSymmetric(TreeNode* root) {
        return root && isSymmetric_(root->left, root->right);
    }
​
private:
    /* This is a recursive approach. */
    bool isSymmetric_(TreeNode* left, TreeNode* right) {
        if (!isBothNullOrEqualVal_(left, right)) {
            return false;
        }
        if (isBothNull_(left, right)) {
            return true;
        }
        return isSymmetric_(left->left, right->right)
            && isSymmetric_(left->right, right->left);
    }
​
    bool isBothNullOrEqualVal_(TreeNode* n, TreeNode* m) {
        if (isBothNull_(n, m)) {
            return true;
        }
        if ((!n) || (!m)) {
            return false;
        }
        return n->val == m->val;
    }
​
    bool isBothNull_(TreeNode* n, TreeNode* m) {
        return (!n) && (!m);
    }
};
​
