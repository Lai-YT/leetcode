use std::collections::HashMap;

impl Solution {
    /// Dynamic programming.
    /// Time complexity: O(n * m);
    /// Space complexity: O(m);
    /// where n and m is the number of rods and the sum of the length of rods, respectively.
    pub fn tallest_billboard(rods: Vec<i32>) -> i32 {
        let mut diffs_to_taller = HashMap::<i32, i32>::new();
        // shorter = taller = 0
        diffs_to_taller.insert(0, 0);
        for rod in rods {
            let old_diffs_to_taller = diffs_to_taller.clone();
            for (diff, taller) in &old_diffs_to_taller {
                // 1. add to taller
                {
                    let new_taller = taller + rod;
                    diffs_to_taller
                        .entry(diff + rod)
                        .and_modify(|old_taller| *old_taller = new_taller.max(*old_taller))
                        .or_insert(new_taller);
                }
                // 2. add to shorter
                {
                    let shorter = taller - diff;
                    let new_taller = (shorter + rod).max(*taller);
                    diffs_to_taller
                        .entry((taller - (shorter + rod)).abs())
                        .and_modify(|old_taller| *old_taller = new_taller.max(*old_taller))
                        .or_insert(new_taller);
                }
                // 3. throw away
            }
        }
        *diffs_to_taller.get(&0).unwrap()
    }
}
