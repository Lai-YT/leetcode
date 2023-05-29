impl Solution {
  pub fn find_cheapest_price(n: i32, flights: Vec<Vec<i32>>, src: i32, dst: i32, k: i32) -> i32 {
      let mut price_of_flights: Vec<Vec<(i32, i32)>> = vec![Vec::new(); n as usize];
      for flight in flights.iter() {
          let city = flight[0];
          let neighbor = flight[1];
          let price = flight[2];
          price_of_flights[city as usize].push((neighbor, price));
      }

      let mut cheapest_price_from_src = vec![i32::MAX; n as usize];
      use std::collections::VecDeque;
      let mut reachable_in_i_hops = VecDeque::<(i32 /* dst */, i32 /* price */)>::new();
      reachable_in_i_hops.push_back((src, 0));
      let mut hop = 0;
      while hop <= k && !reachable_in_i_hops.is_empty() {
          let cities_in_i_hops = reachable_in_i_hops.len();
          for _ in 0..cities_in_i_hops {
              let (city, price) = reachable_in_i_hops.pop_front().unwrap();
              for (neighbor, price_to_neighbor) in price_of_flights[city as usize].clone() {
                  let price_through_city = price + price_to_neighbor;
                  if price_through_city < cheapest_price_from_src[neighbor as usize] {
                      cheapest_price_from_src[neighbor as usize] = price_through_city;
                      reachable_in_i_hops.push_back((neighbor, price_through_city));
                  }
              }
          }
          hop += 1;
      }
      if cheapest_price_from_src[dst as usize] == i32::MAX {
          -1
      } else {
          cheapest_price_from_src[dst as usize]
      }
  }
}
