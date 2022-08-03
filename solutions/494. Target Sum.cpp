class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        nums_ = nums;
        target_ = target;
        count_ = 0;
        DepthFirstSearch_(nums.size() - 1, 0);
        return count_;
    }
​
private:
    std::vector<int> nums_{};
    int target_{};
    int count_{};
​
    void DepthFirstSearch_(const size_t pos, const int sum) {
        if (pos == 0) {
            if (sum + nums_.at(pos) == target_) {
                ++count_;
            }
            if (sum - nums_.at(pos) == target_) {
                ++count_;
            }
            return;
        }
        int curr = nums_.at(pos);
        DepthFirstSearch_(pos - 1, sum + curr);
        DepthFirstSearch_(pos - 1, sum - curr);
    }
};
​
​
​
