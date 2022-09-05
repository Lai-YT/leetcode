// Definition for a Node.
/*
class Node {
 public:
  int val;
  std::vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};
*/

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(Node* root) {
    VisitLevelByLevel_(root);
    return values_in_level_order_;
  }

 private:
  /* to do level order, use FIFO */
  std::queue<Node*> queue_{};

  std::vector<std::vector<int>> values_in_level_order_{};

  void VisitLevelByLevel_(Node* const root) {
    queue_.push(root);
    while (!queue_.empty()) {
      std::vector<int> values = GetValuesOfLevel_(queue_.size());
      if (!values.empty()) {
        values_in_level_order_.push_back(std::move(values));
      }
    }
  }

  std::vector<int> GetValuesOfLevel_(int node_count_of_level) {
    auto values = std::vector<int>{};
    while (node_count_of_level--) {
      Node* node = queue_.front();
      queue_.pop();
      if (node) {
        values.push_back(node->val);
        PushChildrenIntoQueue_(node);
      }
    }
    return std::move(values);
  }

  void PushChildrenIntoQueue_(const Node* const node) {
    for (Node* const child : node->children) {
      queue_.push(child);
    }
  }
};
