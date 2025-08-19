#include <bits/stdc++.h>

class Solution {
public:
    long long zeroFilledSubarray(std::vector<int>& nums) {
        auto count = 0ll;
        auto ans = 0ll;
        for (int n : nums) {
            if (n == 0) {
                ++count;
                continue;
            }
            // We'll have:
            // len 1: count
            // len 2: count - 1
            // len 3: count - 2
            // ...
            // len l: count - (l - 1)
            // Why? Think as a sliding window.
            // Thus, the total number contributed by this subarray is calculated
            // with the trapezoidal rule.
            ans += (1 + count) * count / 2;
            count = 0;
        }
        ans += (1 + count) * count / 2;
        return ans;
    }
};
