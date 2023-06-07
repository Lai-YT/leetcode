use std::collections::{BinaryHeap, HashMap};

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
        // Second, traverse the frequencies and put them into a MaxHeap, so that
        // we can retrieve the biggest k frequencies.
        // Note that while the average time complexity of `push` is O(1),
        // its worst case is O(log(n)), which leads to O(n*log(n)) overall.
        let mut max_heap = BinaryHeap::<(i32, i32)>::new();
        for (num, frequency) in num_and_frequencies {
            // sort by the frequency
            max_heap.push((frequency, num));
        }
        // Third, pop the nums with the top k frequencies, which is O(k*log(n)).
        let mut top_k = Vec::<i32>::with_capacity(k as usize);
        for _ in 0..k {
            if let Some((_frequency, num)) = max_heap.pop() {
                top_k.push(num);
            } else {
                unreachable!()
            }
        }
        top_k
    }
}
