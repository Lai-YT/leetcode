impl Solution {
  pub fn dominant_index(nums: Vec<i32>) -> i32 {
      let (max, max_i) = nums
          .iter()
          .enumerate()
          .map(|(i, num)| (*num, i))
          .max()
          .unwrap();
      for num in nums {
          if num != max && num * 2 > max {
              return -1;
          }
      }
      max_i as i32
  }
  // NOTE: can also be solved by comparing the largest and second largest num, thus a single pass suffices.
}
