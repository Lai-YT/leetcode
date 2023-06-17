class Solution {
 public:
  // Calculate all possibilities with dynamic programming.
  // Time complexity: O(m * n * log(n));
  // Space complexity: O(m * n);
  // where m and n is the length of arr1 and arr2, respectively.
  int makeArrayIncreasing(std::vector<int>& arr1, std::vector<int>& arr2) {
    const std::vector<int>& arr = arr1;     // just a rename
    std::vector<int>& replace_pool = arr2;  // just a rename
    // 1. Sort the replace pool and remove duplicate since positions are
    // irrelevant.
    std::sort(replace_pool.begin(), replace_pool.end());
    replace_pool.erase(/* the begin of the duplicate elements */ std::unique(
                           replace_pool.begin(), replace_pool.end()),
                       replace_pool.end());

    // A certain replace number can be used unlimited times, so we don't have to
    // record such information.
    // When checking the ith number, the 0 ~ (i - 1) numbers are assumed to be
    // strictly increasing, so we don't have to care about them.

    // 2. Use dynamic programming to record if the ith number in arr is
    // replaced by the jth number in the replace pool, what's the minimum number
    // of replacements to have it strictly increasing.
    // So the table has to be n x (m + 1), where n is the length of arr, and m
    // is the length of the replace pool. The additional 1 is for not making
    // replacement.
    std::vector<std::vector<int>> dp(
        arr.size(), std::vector<int>(replace_pool.size() + 1, NO_WAY_));
    // NOTE: the index of not making replacement is the last one.
    const std::size_t no_replace_idx = replace_pool.size();
    // For the last number in arr, which is the initial cases of the dynamic
    // programming, since a single number is itself strictly increasing, the
    // minimum number of replacements is 1.
    dp[arr.size() - 1] = std::vector<int>(replace_pool.size() + 1, 1);
    dp[arr.size() - 1][no_replace_idx] = 0;
    // Start building the table. The index of the first dimension is the ith
    // number in arr, and the second dimension is the jth number in the replace
    // pool. The corresponding value is the minimum number of replacements if we
    // replace the ith number in arr with the jth number in the replacement
    // pool. This specific replacement also is also counted.
    for (int i = arr.size() - 1 - 1; i >= 0; i--) {  // bottom up
      for (std::size_t j = 0; j < replace_pool.size() - 1; j++) {
        // j + 1 since the (i + 1)th number can't be replaced with the jth
        // number anymore, otherwise not strictly increasing.
        dp[i][j] =
            1 + (arr[i + 1] > replace_pool[j]
                     ? r_(std::min(dp[i + 1][j + 1], dp[i + 1][no_replace_idx]))
                     : r_(dp[i + 1][j + 1]));
      }
      // For the last possible replacement, if after replacement, the ith number
      // is still greater than or equal to the (i + 1)th number, there's no way
      // we make arr strictly increasing.
      dp[i][replace_pool.size() - 1] =
          replace_pool[replace_pool.size() - 1] >= arr[i + 1]
              ? NO_WAY_
              : 1 + r_(dp[i + 1][no_replace_idx]);
      // For the non-replacing one, find the index k of the smallest number
      // which is greater than the ith number in arr from the replacement pool.
      const std::size_t k = std::distance(
          replace_pool.begin(),
          std::partition_point(replace_pool.begin(), replace_pool.end(),
                               [&arr, i](const int n) { return n <= arr[i]; }));
      dp[i][no_replace_idx] = k == replace_pool.size()  // all smaller than ith
                                  ? NO_WAY_
                                  : dp[i + 1][k];
      // Also if the (i + 1)th number itself is greater than the ith number,
      // it's minimum number of replacements by not replacing can be taken into
      // account.
      if (arr[i + 1] > arr[i]) {
        dp[i][no_replace_idx] =
            std::min(dp[i][no_replace_idx], dp[i + 1][no_replace_idx]);
      }
    }

    const int min = *std::min_element(dp[0].begin(), dp[0].end());
    return min == NO_WAY_ ? -1 : min;
  }

 private:
  // So is never being considered as the minimum.
  const int NO_WAY_ = std::numeric_limits<int>::max();

  /// @return n - 1 if n equal to NO_WAY_; otherwise n.
  /// @note 1 + r_(n) will never overflow. This is a trick to make our life
  /// easier.
  int r_(const int n) const { return n == NO_WAY_ ? n - 1 : n; }
};
