class Solution {
 public:
  static constexpr int NUM_OF_WHEELS = 4;
​
  /* refer to:
   * https://leetcode.com/problems/open-the-lock/discuss/1250580/C%2B%2BJavaPython-BFS-Level-Order-Traverse-Clean-and-Concise
   */
  int openLock(std::vector<std::string>& deadends, std::string target) {
    /* the visiteds will also be added into deadends */
    std::unordered_set<std::string> deadSet{deadends.cbegin(), deadends.cend()};
    if (deadSet.count("0000")) {
      return -1;
    }
    std::queue<std::string> nextCombinations({"0000"});
    for (int numOfTurns = 0; !nextCombinations.empty(); ++numOfTurns) {
      for (int i = nextCombinations
                       .size() /* these combination are from the previous
                                  exploration, which means they can be reached
                                  with the same number of turns */
           ;
           i > 0; --i) {
        auto comb = nextCombinations.front();
        nextCombinations.pop();
        if (comb == target) {
          return numOfTurns;
        }
        for (auto& nei : neighbors_(comb)) {
          if (!deadSet.count(nei)) {
            deadSet.insert(nei);
            nextCombinations.push(nei);
          }
        }
      }
    }
    return -1;  /* can't reach */
  }
​
 private:
  enum Turn { UP = 1, DOWN = -1 };
​
  std::vector<std::string> neighbors_(const std::string& code) const {
    std::vector<std::string> neighbors{};
    neighbors.reserve(NUM_OF_WHEELS * 2); /* each has 2 neighbors */
    for (size_t i = 0; i < NUM_OF_WHEELS; ++i) {
      for (int turn : {Turn::UP, Turn::DOWN}) {
        std::string nei{code};
        nei.at(i) = (nei.at(i) - '0' + turn + 10 /* no neg. */) % 10 + '0';
        neighbors.push_back(nei);
      }
    }
    return neighbors;
  }
};
