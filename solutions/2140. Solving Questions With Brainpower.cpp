#include <bits/stdc++.h>

class Solution {
    enum {
        POINTS = 0,
        BRAIN_POWER = 1,
    };

public:
    long long mostPoints(std::vector<std::vector<int>>& questions) {
        const auto n = questions.size();

        // The maximum points can get considering only the questions i ~ n,
        // where question i is not taken/taken.
        auto mostPointsFrom = std::vector(n, 0ul);
        mostPointsFrom[n - 1] = questions[n - 1][POINTS];  // taken
        // For bound check.
        auto maxOf = [&](int i) {
            if (i >= n) {
                return 0ul;
            }
            return mostPointsFrom[i];
        };

        for (int i = n - 2; i != -1; i--) {
            auto taken =
                questions[i][POINTS] + maxOf(i + questions[i][BRAIN_POWER] +
                                             1 /* the next can take */);
            auto not_taken = maxOf(i + 1);
            mostPointsFrom[i] = std::max(taken, not_taken);
        }

        return maxOf(0);
    }
};
