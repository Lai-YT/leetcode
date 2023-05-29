class Solution {
public:
  int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src,
                        int dst, int k) {
    auto price_of_flights =
        std::vector<std::vector<std::pair<int /* dst */, int /* price */>>>(n);
    for (const auto &flight : flights) {
      const auto [city, neighbor, price] = getFlightInfo_(flight);
      price_of_flights.at(city).emplace_back(neighbor, price);
    }

    auto cheapest_price_from_src =
        std::vector<int>(n, std::numeric_limits<int>::max());
    auto reachable_in_i_hops =
        std::queue<std::pair<int /* dst */, int /* price */>>{};
    reachable_in_i_hops.emplace(src, 0);
    for (int i = 0; i <= k && !reachable_in_i_hops.empty(); i++) {
      int cities_in_i_hops = reachable_in_i_hops.size();
      while (cities_in_i_hops--) {
        const auto [city, price] = reachable_in_i_hops.front();
        reachable_in_i_hops.pop();
        for (const auto [neighbor, price_to_neighbor] :
             price_of_flights.at(city)) {
          const int price_through_city = price + price_to_neighbor;
          // If reaching the neighbor through the city is cheaper, relax the
          // record and explore such path.
          if (price_through_city < cheapest_price_from_src.at(neighbor)) {
            cheapest_price_from_src.at(neighbor) = price_through_city;
            reachable_in_i_hops.emplace(neighbor, price_through_city);
          }
        }
      }
    }
    return cheapest_price_from_src.at(dst) == std::numeric_limits<int>::max()
               ? -1
               : cheapest_price_from_src.at(dst);
  }

private:
  using FlightInfo_ = std::tuple<int /* price */, int /* dst */, int /* hop */>;

  /// @return src, dst, price
  FlightInfo_ getFlightInfo_(const std::vector<int> &flight) const {
    return {flight.at(0), flight.at(1), flight.at(2)};
  }
};
