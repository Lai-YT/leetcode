#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        auto ans = std::vector(nums.size(), -1);
        // We use a monotonically decreasing stack. Every time we see a number
        // that is greater than the top, the next greater element of such top is
        // found.
        auto stack = std::stack<std::size_t>{};
        // The nums is pretended to be double-length, which is then not
        // circular.
        for (auto ii = 0l; ii < nums.size() * 2; ii++) {
            auto i = ii % nums.size();
            while (!stack.empty() && nums[i] > nums[stack.top()]) {
                // The answer may be set twice because of the double-length, but
                // acceptable since the answer is identical.
                ans[stack.top()] = nums[i];
                stack.pop();
            }
            stack.push(i);
        }
        return ans;
    }
};
