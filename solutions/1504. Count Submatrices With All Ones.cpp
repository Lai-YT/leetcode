#include <bits/stdc++.h>

class Solution {
public:
    int numSubmat(std::vector<std::vector<int>>& mat) {
        auto m = mat.size(), n = mat[0].size();
        auto count = 0;
        // How many consecutive 1s extending upward in column i.
        auto heights = std::vector(n, 0);
        for (auto&& row : mat) {
            for (auto i = 0ul; i < n; i++) {
                // If this row is also 1, increase the height.
                heights[i] = row[i] ? ++heights[i] : 0;
            }
            auto sum = std::vector(n, 0);
            // Find the nearest column on the left that has a smaller height.
            // This can be done using a monotonic stack.
            auto ms = std::stack<int>{};
            for (auto i = 0ul; i < n; i++) {
                while (!ms.empty() && heights[ms.top()] >= heights[i]) {
                    ms.pop();
                }
                if (!ms.empty()) {
                    auto j = ms.top();
                    sum[i] = sum[j] + heights[i] * (i - j);
                } else {
                    sum[i] = heights[i] * (i + 1);
                }
                ms.push(i);
                count += sum[i];
            }
        }
        return count;
    }
};
