impl Solution {
  pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
      let mut ranges = Vec::<String>::new();
      let mut begin = 0;
      for i in 0..nums.len() {
          if i + 1 == nums.len() || nums[i + 1] != nums[i] + 1 {
              ranges.push(if i == begin {
                  format!("{}", nums[i])
              } else {
                  format!("{}->{}", nums[begin], nums[i])
              });
              begin = i + 1;
          }
      }
      ranges
  }
}
