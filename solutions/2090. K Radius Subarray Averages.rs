impl Solution {
  // Use a sliding window with length 2 * k + 1
  pub fn get_averages(nums: Vec<i32>, k: i32) -> Vec<i32> {
      if k == 0 {
          return nums;
      }
      let mut averages = vec![-1; nums.len()];
      // the sum may overflow i32, so will use i64 as the basic computation unit
      let n = (2 * k + 1) as i64;
      if n > nums.len() as i64 {
          return averages;
      }
      let mut window_sum: i64 = nums[0..n as usize].iter().map(|num| *num as i64).sum();
      averages[k as usize] = (window_sum / n) as i32;
      for right_end in n as usize..nums.len() {
          window_sum += (nums[right_end] - nums[right_end - n as usize]) as i64;
          averages[right_end - k as usize] = (window_sum / n) as i32;
      }
      averages
  }
}
