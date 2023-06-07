use std::collections::HashMap;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        // First, collect the frequency of each numbers.
        // Note that while each `entry` has average time complexity O(1),
        // its worst case is O(n), which leads to O(n^2) overall
        let mut num_and_frequencies = HashMap::<i32, i32>::new();
        for num in &nums {
            num_and_frequencies
                .entry(*num)
                .and_modify(|frequency| *frequency += 1)
                .or_insert(1);
        }
        // Second, collect the numbers and frequencies and sort them in descending order by frequency.
        // This is O(n*log(n)) anyway.
        let mut sorte_by_frequency: Vec<(i32, i32)> = num_and_frequencies.into_iter().collect();
        sorte_by_frequency.sort_by(
            |(_a_n, a_f), (_b_n, b_f)| b_f.cmp(a_f), /* descending order */
        );
        // Third, collect the numbers with the top-k frequency.
        // This is O(k).
        sorte_by_frequency[0..k as usize]
            .iter()
            .map(|(n, _f)| *n)
            .collect()
    }
}
