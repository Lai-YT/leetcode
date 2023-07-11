impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let actual_sum = nums.iter().sum::<i32>();
        let expected_sum = ((nums.len() + 0) * (nums.len() + 1) / 2) as i32;
        expected_sum - actual_sum
    }
}
