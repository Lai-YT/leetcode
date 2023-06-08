impl Solution {
  pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
      // Go from the upper right to the lower left to get the
      // border of the negative numbers.

      // We'll count the non-negative numbers to avoid too many arithmetics.
      let mut m = 0;
      let mut n = grid[0].len() - 1;
      let mut count = 0;
      while m < grid.len() {
          // Every time we move to the left, m implies how many non-negative
          // numbers there are.
          if grid[m][n] < 0 {
              count += m;
              // If we saw all the columns, we're done.
              if n == 0 {
                  break;
              }
              n -= 1;
          } else {
              m += 1;
              // If we touched the ground, we'll move horizontally to the left.
              if m == grid.len() {
                  count += m;
                  m -= 1;
                  // If we saw all the columns, we're done.
                  if n == 0 {
                      break;
                  }
                  n -= 1;
              }
          }
      }
      (grid.len() * grid[0].len() - count) as i32
  }
}
