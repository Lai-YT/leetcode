impl Solution {
  pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
      let largest_pile = *piles.iter().max().unwrap();
      let mut left = 1;
      // faster than the largest pile is a waste
      let mut right = largest_pile;
      let mut mid = (left + right) / 2;
      while left < right {
          if Self::get_required_hours(&piles, mid) <= h {
              // mid is currently the smallest possible speed, we keep it
              right = mid;
          } else {
              // mid is not a possible speed, skip it
              left = mid + 1;
          }
          mid = (left + right) / 2;
      }
      // the smallest possible speed overall
      right
  }

  fn get_required_hours(piles: &Vec<i32>, speed: i32) -> i32 {
      piles.iter().fold(0, |acc, pile| {
          // ceil(pile / speed)
          let required_hour = (pile + (speed - 1)) / speed;
          acc + required_hour
      })
  }
}
