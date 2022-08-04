/* formatted with `clang-format --style=llvm` */
​
class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    nums_ = nums;
    total_ = std::accumulate(nums.begin(), nums.end(), 0);
    memo_ = std::vector(
        nums.size(),
        std::vector(total_ * 2 +
                        1, /* to keep sum_ + total_ non-negative and in-range */
                    PLACE_HOLDER_));
    target_ = target;
    return depthFirstSearch_(0, 0);
  }
​
private:
  std::vector<int> nums_{};
  std::vector<std::vector<int>> memo_{};
  int total_{};
  int target_{};
  const int PLACE_HOLDER_{-1}; /* as the count in memo_ can't be negative */
​
  int depthFirstSearch_(const size_t pos, const int sum) {
    if (pos == nums_.size()) {
      if (sum == target_) {
        return 1;
      }
      return 0;
    }
    if (!isMemoized_(memo_.at(pos).at(total_ + sum))) {
      const int curr = nums_.at(pos);
      memo_.at(pos).at(total_ + sum) = depthFirstSearch_(pos + 1, sum + curr) +
                                       depthFirstSearch_(pos + 1, sum - curr);
    }
    return memo_.at(pos).at(total_ + sum);
  }
​
  bool isMemoized_(const int val) const { return val != PLACE_HOLDER_; }
};
​
