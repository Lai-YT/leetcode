class Solution {
public:
  int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src,
                        int dst, int k) {
    buildPriceTable_(n, flights);
    initCacheTable_(n);
    return findCheapestPrice_(src, dst, k);
  }

private:
  const int CANNOT_REACH = -1;
  /// @note the index of the vector is the src flight
  std::vector<std::unordered_map<int /* dst */, int /* price*/>> price_table_{};
  /// @note the index of the vector is the src flight
  std::vector<std::vector<std::unordered_map<int /* hop */, int /* price */>>>
      cache_table_{};

  void buildPriceTable_(int n, const std::vector<std::vector<int>> &flights) {
    price_table_.resize(n);
    for (const auto &flight : flights) {
      const int source = flight.at(0);
      const int destination = flight.at(1);
      const int price = flight.at(2);
      price_table_.at(source).emplace(destination, price);
    }
  }

  void initCacheTable_(int n) {
    cache_table_ = std::vector<
        std::vector<std::unordered_map<int /* hop */, int /* price */>>>(
        n, std::vector<std::unordered_map<int /* hop */, int /* price */>>(n));
  }

  int findCheapestPrice_(int src, int dst, int hop) {
    const auto &cities = price_table_.at(src);
    if (hop < 0 || cities.empty()) {
      return CANNOT_REACH;
    }
    std::vector<int> prices{};
    prices.reserve(cities.size());
    for (const auto &city : cities) {
      if (city.first == dst) {
        prices.push_back(city.second);
        continue;
      }
      int cheapest_price_from_city;
      if (hasCache_(city.first, dst, hop - 1)) {
        cheapest_price_from_city =
            cache_table_.at(city.first).at(dst).at(hop - 1);
      } else {
        cheapest_price_from_city = findCheapestPrice_(city.first, dst, hop - 1);
      }
      if (cheapest_price_from_city != CANNOT_REACH) {
        prices.push_back(city.second + cheapest_price_from_city);
      }
    }
    const int cheapest_price =
        prices.empty() ? CANNOT_REACH
                       : *std::min_element(prices.begin(), prices.end());
    addCache_(src, dst, hop, cheapest_price);
    return cheapest_price;
  }

  bool hasCache_(int src, int dst, int hop) {
    const auto &cache = cache_table_.at(src).at(dst);
    return !cache.empty() && cache.count(hop);
  }

  void addCache_(int src, int dst, int hop, int price) {
    cache_table_.at(src).at(dst).emplace(hop, price);
  }
};
