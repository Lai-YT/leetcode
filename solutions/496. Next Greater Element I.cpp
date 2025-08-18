#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1,
                                        std::vector<int>& nums2) {
        // Scan through nums2 and find the next greater number for all numbers.
        // This can be done with a monotonically decreasing stack.
        auto map = std::unordered_map<int, int>{};
        auto stack = std::stack<int>{};
        for (auto&& n2 : nums2) {
            while (!stack.empty() && n2 > stack.top()) {
                map[stack.top()] = n2;
                stack.pop();
            }
            stack.push(n2);
        }
        auto ans = std::vector<int>{};
        ans.reserve(nums1.size());
        for (auto&& n1 : nums1) {
            if (map.contains(n1)) {
                ans.push_back(map[n1]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
