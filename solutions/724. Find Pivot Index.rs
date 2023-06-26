impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let prefix_sum = nums
            .iter()
            .scan(0, |state, &num| {
                *state += num;
                Some(*state)
            })
            .collect::<Vec<_>>();
        let sum = prefix_sum[nums.len() - 1];
        for i in 0..nums.len() {
            let left_sum = sum - prefix_sum[i];
            let right_sum = if i == 0 { 0 } else { prefix_sum[i - 1] };
            if left_sum == right_sum {
                return i as i32;
            }
        }
        -1
    }
}
