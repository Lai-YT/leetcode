impl Solution {
  // Boyer-Moore Voting Algorithm
  pub fn majority_element(nums: Vec<i32>) -> i32 {
      let mut count = 0;
      let mut candidate = nums[0];
      for num in nums {
          if count == 0 {
              candidate = num;
          }
          count += if num == candidate { 1 } else { -1 }
      }
      candidate
  }
}
