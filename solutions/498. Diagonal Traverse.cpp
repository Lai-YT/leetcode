#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        // The sum of x and y of the elements in a diagnoal are the same.
        auto res = std::vector<int>{};
        res.reserve(m * n);
        // The way of traversing the diagnoal is alternating.
        bool fromLargestX = false;
        for (auto sum = 0; sum <= (m - 1) + (n - 1); sum++) {
            if (fromLargestX) {
                auto x = std::min(sum, n - 1);
                while (sum - x < m && x >= 0) {
                    auto y = sum - x;
                    res.push_back(mat[y][x]);
                    --x;
                }
            } else {
                auto y = std::min(sum, m - 1);
                while (sum - y < n && y >= 0) {
                    auto x = sum - y;
                    res.push_back(mat[y][x]);
                    --y;
                }
            }
            fromLargestX = !fromLargestX;
        }
        return res;
    }
};
