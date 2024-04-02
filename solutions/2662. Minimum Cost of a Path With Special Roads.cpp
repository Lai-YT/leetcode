#include <cmath>
#include <functional>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>

using std::vector;

//
// NOTE: roads are directional
//

class Solution {

public:
  struct TupleHasher {
    auto operator()(const std::tuple<int, int> &t) const {
      return std::hash<int>()(std::get<0>(t)) ^
             std::hash<int>()(std::get<1>(t));
    }
  };

  int minimumCost(vector<int> &start, vector<int> &target,
                  vector<vector<int>> &specialRoads) {
    auto min_heap =
        std::priority_queue<std::tuple<int, int, int>,
                            std::vector<std::tuple<int, int, int>>,
                            std::greater<std::tuple<int, int, int>>>{};
    auto min_cost = std::numeric_limits<int>::max();
    min_heap.emplace(0, start.at(0), start.at(1));
    auto visited = std::unordered_set<std::tuple<int, int>, TupleHasher>{{}};
    while (!min_heap.empty()) {
      auto [cost, x, y] = min_heap.top();
      min_heap.pop();
      if (visited.count({x, y})) {
        continue;
      }
      visited.emplace(x, y);
      min_cost =
          std::min(min_cost, cost + dist(x, y, target.at(0), target.at(1)));
      for (const auto &sr : specialRoads) {
        auto special_cost = sr.at(4);
        min_heap.emplace(cost + dist(x, y, sr.at(0), sr.at(1)) + special_cost,
                         sr.at(2), sr.at(3));
      }
    }
    return min_cost;
  }

private:
  static int dist(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
  }
};
