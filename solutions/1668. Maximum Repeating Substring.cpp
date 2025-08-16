#include <bits/stdc++.h>

class Solution {
  enum {
    MATCH_FROM_ZERO = 0,
    NOT_MATCH_FROM_ZERO = 1,
  };

public:
  int maxRepeating(std::string seq, std::string word) {
    if (seq.size() < word.size()) {
      return 0;
    }
    auto seq_view = std::string_view{seq};
    auto maxFrom = std::vector(seq.size() + 1 /* protect out-of-range */,
                               std::vector{0, 0});
    // To calculate maxFrom[i][MATCH_FROM_ZERO],
    // there must be a match from i. It is then 1 + maxFrom[i +
    // word.size()][MATCH_FROM_ZERO].
    // For the maxFrom[i][NOT_MATCH_FROM_ZERO],
    // It is max(maxFrom[i + 1][MATCH_FROM_ZERO], maxFrom[i +
    // 1][NOT_MATCH_FROM_ZERO]).
    for (auto i = seq.size() - word.size(); i != -1ul; i--) {
      if (seq_view.substr(i).starts_with(word)) {
        maxFrom[i][MATCH_FROM_ZERO] =
            1 + maxFrom[i + word.size()][MATCH_FROM_ZERO];
      } else {
        // The max repeating cannot start at i.
        maxFrom[i][MATCH_FROM_ZERO] = 0;
      }
      maxFrom[i][NOT_MATCH_FROM_ZERO] = std::max(
          maxFrom[i + 1][MATCH_FROM_ZERO], maxFrom[i + 1][NOT_MATCH_FROM_ZERO]);
    }
    return std::max(maxFrom[0][MATCH_FROM_ZERO],
                    maxFrom[0][NOT_MATCH_FROM_ZERO]);
  }
};
