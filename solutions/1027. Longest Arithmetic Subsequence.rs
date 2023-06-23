impl Solution {
  pub fn longest_arith_seq_length(nums: Vec<i32>) -> i32 {
      let mut diff_to_length_end_at_num =
          vec![[1 /* length, self */; 1001/* possible diff: -500 ~ 500 */]; nums.len()];
      let mut max = 1;
      for i in 1..nums.len() {
          for j in 0..i {
              let diff = nums[i] - nums[j];
              let offset_diff = (diff + 500) as usize;
              diff_to_length_end_at_num[i][offset_diff] =
                  diff_to_length_end_at_num[j][offset_diff] + 1;
              max = max.max(diff_to_length_end_at_num[i][offset_diff]);
          }
      }
      max
  }
}
