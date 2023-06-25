impl Solution {
  const MODULO: i32 = 1_000_000_007;

  pub fn count_routes(locations: Vec<i32>, start: i32, finish: i32, fuel: i32) -> i32 {
      let mut counts_from_i_with_fuel = vec![vec![-1; fuel as usize + 1]; locations.len()];
      Self::reach_to_finish(
          &locations,
          start as usize,
          finish as usize,
          fuel,
          &mut counts_from_i_with_fuel,
      );
      counts_from_i_with_fuel[start as usize][fuel as usize]
  }

  fn reach_to_finish(
      locations: &Vec<i32>,
      start: usize,
      finish: usize,
      fuel: i32,
      counts_from_i_with_fuel: &mut Vec<Vec<i32>>,
  ) {
      let mut count = 0;
      if start == finish {
          // we have one way to reach finish
          // NOTE: do not return because finish may be reached multiple times
          count = 1;
      }
      for i in 0..locations.len() {
          if i == start {
              continue;
          }
          let fuel_to_i = (locations[i] - locations[start]).abs();
          let fuel_remaining = fuel - fuel_to_i;
          if fuel_remaining < 0 {
              continue;
          }
          if counts_from_i_with_fuel[i][fuel_remaining as usize] == -1 {
              Self::reach_to_finish(
                  locations,
                  i,
                  finish,
                  fuel_remaining,
                  counts_from_i_with_fuel,
              );
          }
          count = (count + counts_from_i_with_fuel[i][fuel_remaining as usize]) % Self::MODULO;
      }
      counts_from_i_with_fuel[start][fuel as usize] = count;
  }
}
