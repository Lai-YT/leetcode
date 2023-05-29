class Solution {
public:
  using FlightInfo = std::tuple<int /* price */, int /* dst */, int /* hop */>;
  // Dijkstra
  int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src,
                        int dst, int k) {
    auto price_of_flights =
        std::vector<std::vector<std::pair<int /* dst */, int /* price */>>>(n);
    for (const auto &flight : flights) {
      const auto [city, neighbor, price] = getFlightInfo_(flight);
      price_of_flights.at(city).emplace_back(neighbor, price);
    }
    // index is the dst flight
    auto hops_from_src = std::vector<int>(n, std::numeric_limits<int>::max());
    auto min_heap = std::priority_queue<FlightInfo, std::vector<FlightInfo>,
                                        std::greater<FlightInfo>>{};
    min_heap.emplace(0, src, -1);

    // Keeps choosing the one with the cheapest price, reaching out until dst is
    // reached.
    while (!min_heap.empty()) {
      const auto [price, destination, hop] = min_heap.top();
      min_heap.pop();
      // NOTE: since this is a min heap, the price is guaranteed to be cheaper.
      if (hop > hops_from_src.at(destination) || hop > k) {
        // if we've already encountered a path with a lower price and fewer
        // hops, or the number of hops exceeds the limit, ignore and move on
        continue;
      }
      // if haven't reached yet or has cheaper price, update it
      hops_from_src.at(destination) = hop;
      if (destination == dst) {
        return price;
      }
      for (const auto [neighbor, price_to_neighbor] :
           price_of_flights.at(destination)) {
        min_heap.emplace(price + price_to_neighbor, neighbor, hop + 1);
      }
    }
    return -1;
  }

private:
  /// @return src, dst, price
  FlightInfo getFlightInfo_(const std::vector<int> &flight) const {
    return {flight.at(0), flight.at(1), flight.at(2)};
  }
};
