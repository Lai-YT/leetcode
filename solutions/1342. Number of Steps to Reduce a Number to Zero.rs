impl Solution {
  pub fn number_of_steps(num: i32) -> i32 {
      if num == 0 {
          0
      } else {
          (i32::BITS - num.leading_zeros() - 1 + num.count_ones()) as i32
      }
  }
}
