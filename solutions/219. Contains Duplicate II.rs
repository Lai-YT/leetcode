use std::collections::HashSet;

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut seen = HashSet::with_capacity(k as usize);
        let mut left_end = 0;
        for num in &nums {
            if seen.contains(num) {
                return true;
            }
            seen.insert(num);
            if seen.len() > k as usize {
                seen.remove(&nums[left_end as usize]);
                left_end += 1;
            }
        }
        false
    }
}
