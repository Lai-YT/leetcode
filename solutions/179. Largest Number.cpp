#include <bits/stdc++.h>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        auto num_strs = std::vector<std::string>(nums.size());
        std::ranges::transform(nums, num_strs.begin(),
                               [](const auto& n) { return std::to_string(n); });
        std::ranges::sort(num_strs, isGreater_);
        if (num_strs.front() == "0") {
            // All numbers are zero; only kept a single 0.
            return "0";
        }
        return std::accumulate(num_strs.begin(), num_strs.end(), std::string{});
    }

private:
    static bool isGreater_(std::string_view a, std::string_view b) {
        auto pos = 0l;
        while (pos < a.size() && pos < b.size()) {
            if (a[pos] != b[pos]) {
                return a[pos] > b[pos];
            }
            ++pos;
        }
        if (a.size() == b.size()) {
            // The two strings are identical.
            return false;
        }
        // Since the smaller one of (a, b) will be concatenated after the other,
        // the remaining part of the greater string must be greater as well.
        if (pos == a.size()) {
            return isGreater_(a, b.substr(pos));
        }
        return isGreater_(a.substr(pos), b);
    }
};
