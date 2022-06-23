class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> snums(2 * n);
        for (int x = 0, y = n, shuff = 0; 
             x < n;
             ++x, ++y, shuff += 2) 
        {
            snums.at(shuff) = nums.at(x);
            snums.at(shuff + 1) = nums.at(y);
        }
        return snums;
    }
};
