use std::collections::{BinaryHeap, HashSet};

impl Solution {
    pub fn k_smallest_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        let mut priority_queue = BinaryHeap::from([(
            Self::reverse_sum(nums1[0] + nums2[0]), /* sum */
            0usize,                                 /* nums1 index */
            0usize,                                 /* nums2 index */
        )]);
        let mut pairs_seen = HashSet::<(usize, usize)>::from([(0, 0)]);
        let mut pairs = Vec::<Vec<i32>>::new();
        while !priority_queue.is_empty() && pairs.len() < k as usize {
            let (_, i, j) = priority_queue.pop().unwrap();
            pairs.push(Vec::from([nums1[i], nums2[j]]));
            if i + 1 < nums1.len() && !pairs_seen.contains(&(i + 1, j)) {
                priority_queue.push((Self::reverse_sum(nums1[i + 1] + nums2[j]), i + 1, j));
                pairs_seen.insert((i + 1, j));
            }
            if j + 1 < nums2.len() && !pairs_seen.contains(&(i, j + 1)) {
                priority_queue.push((Self::reverse_sum(nums1[i] + nums2[j + 1]), i, j + 1));
                pairs_seen.insert((i, j + 1));
            }
        }
        pairs
    }

    /// Changes the sign of `sum`, so that the order is revered.
    #[inline]
    fn reverse_sum(sum: i32) -> i32 {
        -sum
    }
}
