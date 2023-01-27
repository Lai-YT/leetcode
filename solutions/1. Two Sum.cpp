class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> m{};
    for (int i = 0; i < nums.size(); i++) {
      const int complement = target - nums.at(i);
      if (m.count(complement) != 0) {
        return {i, m.at(complement)};
      } else {
        m[nums.at(i)] = i;
      }
    }
    return {};
  }
};
