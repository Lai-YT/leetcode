impl Solution {
    pub fn sort_by_bits(arr: Vec<i32>) -> Vec<i32> {
        let mut arr = arr;
        arr.sort_by(|a, b| {
            match a.count_ones().cmp(&b.count_ones()) {
                std::cmp::Ordering::Equal => a.cmp(b),
                other => other,
            }
        });
        arr
    }
}
