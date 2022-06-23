class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums.at(0)) {
            return 0;
        }
        int curr = 0, next = 1;
        while (next < nums.size()) {
            if (nums.at(curr) <= target && nums.at(next) >= target) {
                return next;
            }
            curr++, next++;
        }
        return next;
    }
};
