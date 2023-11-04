#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  /// @details Using Dijkstra's algorithm to find the shortest paths from the
  /// source to every other nodes.
  int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
    //
    // Initialize graph.
    //

    constexpr auto kInfinity = std::numeric_limits<int>::max();
    int distances[n];
    std::fill(distances, distances + n, kInfinity);
    // init source
    distances[NodeNoToIndex_(k)] = 0;

    // Each node is visited only once. The shortest path can be obtained in this
    // single visitation greedily.
    bool visits[n];
    std::fill(visits, visits + n, false);

    auto edges =
        std::vector<std::vector<std::pair<int /* neighbor */, int /* time */>>>(
            n);
    for (auto &edge : times) {
      auto from = edge.at(0);
      auto to = edge.at(1);
      auto time = edge.at(2);
      edges.at(NodeNoToIndex_(from)).emplace_back(to, time);
    }

    //
    // Relax all edges.
    // NOTE: since we do not return early when reaching a specific node, we get
    // the shortest path to all other nodes from the source.
    //

    auto min_heap =
        std::priority_queue<std::pair<int /* distance */, int /* to */>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>{};
    min_heap.emplace(0, k);
    while (!min_heap.empty()) {
      auto [_, to] = min_heap.top();
      min_heap.pop();
      if (visits[NodeNoToIndex_(to)]) {
        continue;
      }
      visits[NodeNoToIndex_(to)] = true;
      for (auto [neighbor, time] : edges.at(NodeNoToIndex_(to))) {
        // NOTE: be careful for the overflow when the distance is infinity
        auto alter_path = distances[NodeNoToIndex_(to)] == kInfinity
                              ? kInfinity
                              : distances[NodeNoToIndex_(to)] + time;
        if (alter_path < distances[NodeNoToIndex_(neighbor)]) {
          // getting to edge.to through node i is shorter
          distances[NodeNoToIndex_(neighbor)] = alter_path;
          // keep exploring in this way
          min_heap.emplace(distances[NodeNoToIndex_(neighbor)], neighbor);
        }
      }
    }

    //
    // Get the shortest path.
    //

    int longest_shortest_path = *std::max_element(distances, distances + n);
    if (longest_shortest_path == kInfinity) {
      return -1;
    }
    return longest_shortest_path;
  }

private:
  /// @brief This is a conversion function to map the number of node, which
  /// starts from 1, to the index of arrays.
  static std::size_t NodeNoToIndex_(int node_no) { return node_no - 1; }
};
