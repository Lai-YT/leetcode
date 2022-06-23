class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums.at(0);
        int count = 0;
        for (int n : nums) {
            if (!count) {
                res = n;
                ++count;
            }
            else if (n == res) ++count;
            else --count;
        }
        return res;
    }
};
