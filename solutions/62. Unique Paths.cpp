#include <bits/stdc++.h>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Use 1-based for easy bound handling.

        // Number of paths to reach (y, x).
        // Optimized for space: since we only required the previous y, memoize
        // the previous y and overwrite on the fly.
        auto memo = std::vector(n + 1, 0);
        memo[1] = 1;
        // memo[y][x] = memo[y - 1][x] + memo[y][x - 1];
        // Compute from left to right, top to bottom, so that the required memos
        // are always computed.
        for (int y = 1; y <= m; y++) {
            for (int x = 1; x <= n; x++) {
                if (y == 1 && x == 1) [[unlikely]] {
                    continue;
                }
                memo[x] = memo[x] + memo[x - 1];
            }
        }
        return memo[n];
    }
};
