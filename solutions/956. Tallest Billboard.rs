use std::collections::{HashMap, HashSet};

impl Solution {
    /// Meet in the Middle.
    /// Time complexity: O(3 ^ (n / 2)), exponential time.
    /// Space complexity: O(3 ^ (n / 2)).
    pub fn tallest_billboard(rods: Vec<i32>) -> i32 {
        let first_differences =
            Self::get_differences(&Self::get_combinations(&rods[0..rods.len() / 2]));
        let second_differences =
            Self::get_differences(&Self::get_combinations(&rods[rods.len() / 2..]));
        let mut max = 0;
        for (diff, first_left) in first_differences {
            if let Some(second_left) = second_differences.get(&(-1 * diff) /* compensate */) {
                max = max.max(first_left + second_left);
            }
        }
        max
    }

    fn get_combinations(rods: &[i32]) -> HashSet<(i32, i32)> {
        let mut states = HashSet::<(i32 /* left */, i32 /* right */)>::new();
        states.insert((0, 0));
        for rod in rods {
            let mut new_states = HashSet::<(i32, i32)>::new();
            for &(left, right) in &states {
                // 1. add to left
                new_states.insert((left + rod, right));
                // 2. add to right
                new_states.insert((left, right + rod));
                // 3. throw away, no new state
            }
            states.extend(&new_states);
        }
        states
    }

    fn get_differences(states: &HashSet<(i32, i32)>) -> HashMap<i32, i32> {
        let mut differences = HashMap::<i32 /* difference */, i32 /* length of left */>::new();
        for &(left, right) in states {
            differences
                .entry(left - right)
                // we only want the maximum value
                .and_modify(|length| *length = left.max(*length))
                .or_insert(left);
        }
        differences
    }
}
