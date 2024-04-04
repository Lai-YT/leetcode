class Solution {
public:
  int maxDepth(string s) {
    int depth = 0;
    int max_depth = 0;
    for (auto c : s) {
      if (c == '(') {
        ++depth;
        if (depth > max_depth) {
          max_depth = depth;
        }
      } else if (c == ')') {
        --depth;
      }
    }
    return max_depth;
  }
};
