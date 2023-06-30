struct UnionFind {
    roots: Vec<usize>,
    ranks: Vec<usize>,
}

impl Solution {
    const LAND: i32 = 0;
    const WATER: i32 = 1;
    const MOVES: [(i32, i32); 4] = [(1, 0), (0, -1), (-1, 0), (0, 1)];

    /// Union-find on land.
    /// - Time complexity: O(row * col). At most row * col waters to resolve
    /// and each operation on `UnionFind` can be considered as O(1).
    /// - Space complexity: O(row * col). `UnionFind` with all cells.
    pub fn latest_day_to_cross(row: i32, col: i32, cells: Vec<Vec<i32>>) -> i32 {
        // Resolve the nasty types.
        let row = row as usize;
        let col = col as usize;
        let waters = cells
            .iter()
            .map(|c| (c[0] as usize, c[1] as usize))
            .collect::<Vec<_>>();
        // NOTE: 2 extra spaces to indicate the top row group and the bottom row group,
        // once they are connected, we find the cross.
        let mut union_find = UnionFind::new(row * col + 2);
        // Since the `union_find` is 1-dimensional, we'll have to perform a mapping.
        // (1, 1) has to be at 1, (row, col) has to be at `row * col`.
        // NOTE: 1-based index
        let map_index = |cell: (usize, usize)| (cell.0 - 1) * col + (cell.1 - 1) + 1;
        // index 0 and index `row * col + 1` is used as the top and bottom group
        let top_group = 0;
        let bottom_group = row * col + 1;
        // Using the union-find data structure, we are to find the first day
        // which the top row and the bottom row is connected.
        // Start from the last day, where there are no more lands.
        let mut matrix = vec![vec![Self::WATER; col + 1]; row + 1];
        for (day, &new_land) in waters.iter().enumerate().rev() {
            // Flip water to land, connect to its neighbor lands.
            matrix[new_land.0][new_land.1] = Self::LAND;
            for r#move in Self::MOVES {
                if let Some(neighbor_land) = Self::move_to_land(new_land, r#move, &matrix) {
                    union_find.union(map_index(new_land), map_index(neighbor_land));
                }
            }
            // Also if the land is in the top or bottom row, we'll add them into the extra group.
            if new_land.0 == 1 {
                union_find.union(map_index(new_land), top_group);
            }
            if new_land.0 == row {
                union_find.union(map_index(new_land), bottom_group);
            }
            // NOTE: At `day`, the `water` is still there, so the result should be `day - 1`,
            // but because `waters` is 0-based (yes, although others are 1-based),
            // the result is `day`.
            if union_find.is_connected(top_group, bottom_group) {
                return day as i32;
            }
        }
        unreachable!()
    }

    /// Returns the moved cell if such cell is in the matrix and is a piece of land.
    /// - Time complexity: O(1)
    /// - Space complexity: O(1)
    fn move_to_land(
        cell: (usize, usize),
        offset: (i32, i32),
        matrix: &Vec<Vec<i32>>,
    ) -> Option<(usize, usize)> {
        // Since it's 1-based, won't overflow on the attempt.
        let next = (
            (cell.0 as i32 + offset.0) as usize,
            (cell.1 as i32 + offset.1) as usize,
        );
        if next.0 == 0
            || next.1 == 0
            || next.0 == matrix.len()
            || next.1 == matrix[0].len()
            || matrix[next.0][next.1] == Self::WATER
        {
            None
        } else {
            Some(next)
        }
    }
}

impl UnionFind {
    pub fn new(size: usize) -> Self {
        Self {
            // initialize the root as the node itself
            roots: (0..size).collect(),
            ranks: vec![1 /* starts with rank 1 */; size],
        }
    }

    pub fn is_connected(&mut self, a: usize, b: usize) -> bool {
        self.find(a) == self.find(b)
    }

    /// O(1) amortized. Optimized with union by rank.
    pub fn union(&mut self, a: usize, b: usize) {
        let root_a = self.find(a);
        let root_b = self.find(b);
        if root_a != root_b {
            if self.ranks[root_a] > self.ranks[root_b] {
                self.roots[root_b] = root_a;
            } else if self.ranks[root_a] < self.ranks[root_b] {
                self.roots[root_a] = root_b;
            } else {
                // choose `root_a` as the root, doesn't matter
                self.roots[root_b] = root_a;
                self.ranks[root_a] += 1;
            }
        }
    }

    /// Returns the root node of `node`.
    /// O(1) amortized. Optimized with path compression.
    fn find(&mut self, node: usize) -> usize {
        if self.roots[node] == node {
            return node;
        }
        self.roots[node] = self.find(self.roots[node]);
        self.roots[node]
    }
}
