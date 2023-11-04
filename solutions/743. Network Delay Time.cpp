#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  /// @details Using Bellman-Ford algorithm to find the shortest paths from the
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

    //
    // Relax all edges n - 1 times.
    //

    for (auto _ = 0; _ < n - 1; _++) {
      for (auto &edge : times) {
        auto from = edge.at(0);
        auto to = edge.at(1);
        auto time = edge.at(2);
        // NOTE: be careful for the overflow when the distance is infinity
        auto alter_path = distances[NodeNoToIndex_(from)] == kInfinity
                              ? kInfinity
                              : distances[NodeNoToIndex_(from)] + time;
        if (alter_path < distances[NodeNoToIndex_(to)]) {
          // getting to edge.to through node i is shorter
          distances[NodeNoToIndex_(to)] = alter_path;
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
