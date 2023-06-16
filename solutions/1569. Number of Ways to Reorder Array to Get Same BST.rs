impl Solution {
  pub fn num_of_ways(nums: Vec<i32>) -> i32 {
      let combination_table = Self::build_combination_table(nums.len());
      Self::num_of_ways_(&nums, &combination_table) as i32 - 1 /* the original one */
  }

  /// Since the result may be large, we'll take modulo `10^9 + 7`. Also `i64` is to
  /// prevent from overflowing during computations. The result should be convertible
  /// to `i32` without loss.
  fn num_of_ways_(nums: &Vec<i32>, combination_table: &Vec<Vec<i64>>) -> i64 {
      // base case
      if nums.len() < 3 {
          return 1;
      }

      let modulo = 10i64.pow(9) + 7;

      let children = &nums[1..]; // exclude root
      let left_nodes = children
          .iter()
          // BST property: less than
          .filter(|&n| *n < nums[0])
          .map(|n| *n)
          .collect::<Vec<i32>>();
      let right_nodes = children
          .iter()
          // BST property: greater than
          .filter(|&n| *n > nums[0])
          .map(|n| *n)
          .collect::<Vec<i32>>();

      // C(children.len(), left_nodes.len()) * ways in left * ways in right
      combination_table[children.len()][left_nodes.len()]
          * (Self::num_of_ways_(&left_nodes, combination_table)
              * Self::num_of_ways_(&right_nodes, combination_table)
              % modulo)
          % modulo
  }

  /// Builds a table for combinations.
  /// Taking advantage of the Pascal's triangle.
  fn build_combination_table(level: usize) -> Vec<Vec<i64>> {
      let modulo = 10i64.pow(9) + 7;
      let mut combination_table = Vec::<Vec<i64>>::with_capacity(level);
      for i in 0..level {
          combination_table.push(vec![1; i + 1]);
          for j in 1..i {
              combination_table[i][j] =
                  (combination_table[i - 1][j - 1] + combination_table[i - 1][j]) % modulo;
          }
      }
      combination_table
  }
}
