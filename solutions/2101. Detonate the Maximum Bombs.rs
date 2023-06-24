use std::collections::{HashMap, HashSet, VecDeque};

#[derive(Clone, Copy, PartialEq, Eq, Hash, Debug)]
struct Bomb {
    x: usize,
    y: usize,
    r: i32,
}

impl Bomb {
    /// Returns whether `self` is in the range of `other`.
    pub fn is_in_range_of(&self, other: &Bomb) -> bool {
        // convert to i64 to handle possible overflow on i32
        (other.x as i64 - self.x as i64).pow(2) + (other.y as i64 - self.y as i64).pow(2)
            <= (other.r as i64).pow(2)
    }
}

impl Solution {
    // Depth-first search.
    // Time complexity: O(n ^ 3), worse case scenario: complete graph;
    // Space complexity: O(n ^ 2).
    pub fn maximum_detonation(bombs: Vec<Vec<i32>>) -> i32 {
        let mut bombs_in_range = HashMap::<Bomb, Vec<Bomb>>::new();
        // Since there may be multiple bombs with same x, y and r, we'll have to record the occurrences.
        let mut identical_bombs = HashMap::<Bomb, i32 /* occurrence */>::new();
        // 1. Collect reachable bombs of all bombs.
        // Time complexity: O(n ^ 2).
        for i in 0..bombs.len() {
            let bomb = Bomb {
                x: bombs[i][0] as usize,
                y: bombs[i][1] as usize,
                r: bombs[i][2],
            };
            *identical_bombs.entry(bomb).or_insert(0) += 1;
            bombs_in_range.insert(bomb, Vec::new());
            for j in 0..i {
                let other_bomb = Bomb {
                    x: bombs[j][0] as usize,
                    y: bombs[j][1] as usize,
                    r: bombs[j][2],
                };
                if bomb.is_in_range_of(&other_bomb) {
                    bombs_in_range.get_mut(&other_bomb).unwrap().push(bomb);
                }
                if other_bomb.is_in_range_of(&bomb) {
                    bombs_in_range.get_mut(&bomb).unwrap().push(other_bomb);
                }
            }
        }
        // 2. Perform depth-first search on all bombs to obtain how many bombs can be denoted.
        // Time complexity: O(n ^ 3).
        let mut max_num_of_denoted_bombs = 0;
        for i in 0..bombs.len() {
            let init = Bomb {
                x: bombs[i][0] as usize,
                y: bombs[i][1] as usize,
                r: bombs[i][2],
            };
            let mut denoted = HashSet::<Bomb>::from([init]);
            let mut stack = VecDeque::<Bomb>::from([init]);
            let mut num_of_denoted_bombs = *identical_bombs.get(&init).unwrap();
            while !stack.is_empty() {
                let bomb = stack.pop_front().unwrap();
                for bomb_in_range in bombs_in_range.get(&bomb).unwrap() {
                    if !denoted.contains(&bomb_in_range) {
                        stack.push_front(*bomb_in_range);
                        denoted.insert(*bomb_in_range);
                        num_of_denoted_bombs += identical_bombs.get(bomb_in_range).unwrap();
                    }
                }
            }
            max_num_of_denoted_bombs = max_num_of_denoted_bombs.max(num_of_denoted_bombs);
        }
        max_num_of_denoted_bombs
    }
}
