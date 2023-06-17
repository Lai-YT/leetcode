class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int max = 0;
    for (auto& cust : accounts) {
      int sum = 0;
      for (auto mon : cust) {
        sum += mon;
      }
      if (sum > max) {
        max = sum;
      }
    }
    return max;
  }
};
