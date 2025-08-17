#include <bits/stdc++.h>

class Solution {
public:
    int numTrees(int n) {
        memo_ = std::vector(n + 1, kNotMemoized_);
        // These n have only one choice.
        memo_[0] = 1;
        memo_[1] = 1;
        return numTreesRecur_(n);
    }

private:
    int kNotMemoized_ = -1;

    std::vector<int> memo_;

    int numTreesRecur_(int n) {
        if (isMemoized_(n)) {
            return memo_[n];
        }
        // We can choose any number in [1, n] as the root.
        // Then for each choice m,
        //      numTrees(n) += numTrees(m - 1) * numTrees(n - m)
        // Notice that the number of trees with node 1 ~ m is identical
        // with (1 + k) ~ (m + k), where k is any possible number.
        memo_[n] = 0;
        for (int m = 1; m <= n; m++) {
            memo_[n] +=
                numTreesRecur_(m - 1) * numTreesRecur_(n - m /* m + 1 ~ n */);
        }
        return memo_[n];
    }

    int isMemoized_(int n) const { return memo_[n] != kNotMemoized_; }
};
