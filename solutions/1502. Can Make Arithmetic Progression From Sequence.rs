use std::collections::HashSet;
impl Solution {
    pub fn can_make_arithmetic_progression(arr: Vec<i32>) -> bool {
        // length of the arr is at least 2
        let min = arr.iter().min().unwrap();
        let max = arr.iter().max().unwrap();
        // all numbers are the same
        if max == min {
            return true;
        }
        // for arithmetic progression of ints, the common difference must also be an int
        if (max - min) % (arr.len() - 1) as i32 != 0 {
            return false;
        }
        let common_diff = (max - min) / (arr.len() - 1) as i32;
        let mut seen = HashSet::with_capacity(arr.len());
        for num in &arr {
            if (num - min) % common_diff != 0 || seen.contains(num) {
                return false;
            }
            seen.insert(*num);
        }
        true
    }
}
