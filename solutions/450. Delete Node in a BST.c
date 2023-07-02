struct TreeNode* deleteNode(struct TreeNode* root, int key) {
  //
  // 1. Find the node with `key`
  //
  if (!root) {
    // Cannot find the node with `key`.
    return NULL;
  }
  if (key > root->val) {
    root->right = deleteNode(root->right, key);
  } else if (key < root->val) {
    root->left = deleteNode(root->left, key);
  } else {
    // We find the node.
    //
    // 2. If such node is not a leaf node, replace it with the left-most leaf
    // of the right sub-tree. If doesn't have right sub-tree, replace it with
    // the right-most leaf of the left sub-tree.
    //
    struct TreeNode** handle = NULL;
    struct TreeNode* node_to_replace = NULL;
    if (root->right) {
      handle = &root->right;
      while ((*handle)->left) {
        handle = &(*handle)->left;
      }
      node_to_replace = *handle;
      // Remove node_to_replace from the sub-tree.
      // NOTE: if you remove it after the replace, a cycle occur when root is
      // the direct parent of node_to_replace.
      *handle = node_to_replace->right;
    } else if (root->left) {
      handle = &root->left;
      while ((*handle)->right) {
        handle = &(*handle)->right;
      }
      node_to_replace = *handle;
      *handle = node_to_replace->left;
    } else {
      // Is leaf. Simply delete it.
      return NULL;
    }
    node_to_replace->left = root->left;
    node_to_replace->right = root->right;
    root = node_to_replace;
  }
  return root;
}
