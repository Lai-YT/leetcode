class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /* 1. find the turning point (sign change) */
        int turningPoint = 0;
        while (turningPoint < nums.size() && nums.at(turningPoint) < 0) {
            ++turningPoint;
        }
        /* turningPoint ~ (size - 1) are non-negatives;
          0 ~ (turningPoint - 1) are negatives */
        
        /* 2. we now no more need the sign, square up */
        for (int& n : nums) {
            n *= n;
        }
​
        vector<int> result{};
        result.reserve(nums.size());
        /* 3. merge the 2 parts separated by turningPoint into the result */
        int nonnegPos = turningPoint;
        int negPos = turningPoint - 1;
        while (nonnegPos < nums.size() && negPos >= 0) {
            if (nums.at(nonnegPos) < nums.at(negPos)) {
                result.push_back(nums.at(nonnegPos));
                ++nonnegPos;
            } else {
                result.push_back(nums.at(negPos));
                --negPos;
            }
        }
        if (nonnegPos < nums.size()) {
            result.insert(result.cend(), std::next(nums.begin(), nonnegPos), nums.end());
        } else if (negPos >= 0) {
            result.insert(result.cend(), std::prev(nums.rend(), negPos + 1), nums.rend());
        }
​
