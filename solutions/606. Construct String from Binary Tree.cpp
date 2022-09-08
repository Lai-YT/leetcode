class Solution {
 public:
  std::string tree2str(TreeNode *root) {
    if (root) {
      /* root doesn't need outer parenthesis */
      preorder_node_ss_ << root->val;
      VisitChildren_(root);
    }
    return preorder_node_ss_.str();
  }
​
 private:
  std::stringstream preorder_node_ss_{};
​
  void VisitNode_(const TreeNode *const node) {
    if (node) {
      preorder_node_ss_ << '(';
      preorder_node_ss_ << node->val;
      VisitChildren_(node);
      preorder_node_ss_ << ')';
    }
  }
​
  void VisitChildren_(const TreeNode *const node) {
    if (HasOnlyRightChild_(node)) {
      /* make one-to-one mapping */
      preorder_node_ss_ << "()";
    }
    VisitNode_(node->left);
    VisitNode_(node->right);
  }
​
  bool HasOnlyRightChild_(const TreeNode *const node) const {
    return !node->left && node->right;
  }
};
​
