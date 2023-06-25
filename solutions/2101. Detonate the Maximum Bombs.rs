struct Bomb {
    x: usize,
    y: usize,
    r: i32,
}

impl From<Vec<i32>> for Bomb {
    fn from(bomb: Vec<i32>) -> Self {
        match bomb[..] {
            [x, y, r] => Self {
                x: x as usize,
                y: y as usize,
                r,
            },
            _ => panic!(),
        }
    }
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
        let bombs = bombs.into_iter().map(Bomb::from).collect::<Vec<_>>();
        // Instead of using the (x, y) coordinate and r to identify a bomb, we can use the index in bombs.
        // This makes every bombs unique from each other, and hash map can be replaced by a simple array.
        let mut bombs_in_range = vec![Vec::<usize>::new(); bombs.len()];
        // 1. Collect reachable bombs of all bombs.
        // Time complexity: O(n ^ 2).
        for i in 0..bombs.len() {
            for j in 0..i {
                if bombs[i].is_in_range_of(&bombs[j]) {
                    bombs_in_range[j].push(i);
                }
                if bombs[j].is_in_range_of(&bombs[i]) {
                    bombs_in_range[i].push(j);
                }
            }
        }
        // 2. Perform depth-first search on all bombs to obtain how many bombs can be detonated.
        // Time complexity: O(n ^ 3).
        let mut max_num_of_detonated_bombs = 0;
        for i in 0..bombs.len() {
            let mut detonated = vec![false; bombs.len()];
            let mut stack = Vec::<usize>::from([i]);
            while let Some(bomb) = stack.pop() {
                if detonated[bomb] {
                    continue;
                }
                detonated[bomb] = true;
                stack.extend(bombs_in_range[bomb].iter().filter(|&b| !detonated[*b]));
            }
            max_num_of_detonated_bombs =
                max_num_of_detonated_bombs.max(detonated.iter().filter(|&d| *d).count());
        }
        max_num_of_detonated_bombs as i32
    }
}
