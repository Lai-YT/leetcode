impl Solution {
  // What we want is the maximal prefix sum.
  pub fn largest_altitude(gain: Vec<i32>) -> i32 {
      let initial_altitude = 0;
      gain.iter()
          .scan(initial_altitude, |prefix_sum, g| {
              *prefix_sum += *g;
              Some(*prefix_sum)
          })
          .max()
          .unwrap()
          .max(initial_altitude) // if all prefix sums are negative, the initial altitude is the highest
  }
}
