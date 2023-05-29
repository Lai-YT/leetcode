class Solution {
public:
  // Bellman-Ford
  int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src,
                        int dst, int k) {
    initReached_(n, src);

    // K hops => k + 1 edges
    for (std::size_t i = 0; i < k + 1; i++) {
      // Copy so the ith hop only based on the cheapest price of the (i - 1)th
      // hop.
      std::vector<int> cheapest_price_in_i_hops{reached_from_src_};
      for (const auto &flight : flights) {
        const auto [city, neighbor, price] = getFlightInfo_(flight);
        if (isReached_(city)) {
          cheapest_price_in_i_hops.at(neighbor) =
              // if using i hops yield a cheaper price, update it
              std::min(cheapest_price_in_i_hops.at(neighbor),
                       reached_from_src_.at(city) + price);
        }
      }
      reached_from_src_ = cheapest_price_in_i_hops;
    }

    return isReached_(dst) ? reached_from_src_.at(dst) : CANNOT_REACH;
  }

private:
  const int CANNOT_REACH = -1;
  /// @brief Price from source to all other nodes.
  std::vector<int> reached_from_src_;

  /// @return src, dst, price
  std::tuple<int, int, int>
  getFlightInfo_(const std::vector<int> &flight) const {
    return {flight.at(0), flight.at(1), flight.at(2)};
  }

  void initReached_(int num_of_cities, int src) {
    reached_from_src_ =
        std::vector<int>(num_of_cities, std::numeric_limits<int>::max());
    reached_from_src_.at(src) = 0;
  }

  bool isReached_(int city) const {
    return reached_from_src_.at(city) != std::numeric_limits<int>::max();
  }
};
