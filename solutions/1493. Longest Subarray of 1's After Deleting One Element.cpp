#include <bits/stdc++.h>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        auto compressed = std::vector<int>{};
        int max = 0;
        int sum = 0;
        for (auto n : nums) {
            if (n) {
                ++sum;
                continue;
            }
            if (sum) {
                // So that consecutive zeros aren't written twice.
                compressed.push_back(sum);
                max = std::max(max, sum);
            }
            sum = 0;
            compressed.push_back(n);
        }
        if (sum) {
            compressed.push_back(sum);
            max = std::max(max, sum);
        }

        if (compressed.size() == 1 && max) {
            // All ones; delete a one.
            return max - 1;
        }

        for (auto i = 1ul; i < compressed.size() - 1; i++) {
            // If is (..., a, 0, b, ...), deleting this 0 gives a longer
            // subarray a + b.
            auto a = compressed[i - 1];
            auto b = compressed[i + 1];
            if (!compressed[i] && a && b) {
                max = std::max(max, a + b);
            }
        }
        return max;
    }
};
