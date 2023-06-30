impl Solution {
    const LAND: i32 = 0;
    const WATER: i32 = 1;

    /// Depth-first search on days + using binary search to skip some days.
    /// - Time complexity: O(row * col * log(row * col)). O(row * col) for each depth-first search, O(log(`cells.len()`) for the binary search, where `cells.len()` is row * col)
    /// - Space complexity: O(row * col).
    pub fn latest_day_to_cross(row: i32, col: i32, cells: Vec<Vec<i32>>) -> i32 {
        // Resolve the nasty types.
        let row = row as usize;
        let col = col as usize;
        let waters = cells
            .iter()
            .map(|c| (c[0] as usize, c[1] as usize))
            .collect::<Vec<_>>();
        // lower bound: the latest day we currently know that can cross.
        // upper bound: the farthest day that might cross.
        let mut day_range = (0usize, waters.len());
        while day_range.0 != day_range.1 {
            let day = (day_range.0 + day_range.1 + 1/* so we don't get stuck when `day_range.1 == day_range.0 + 1` */)
                / 2;
            if Self::can_cross(row, col, &waters[0..day]) {
                // Adjust the latest day that can cross to `day`.
                day_range = (day, day_range.1);
            } else {
                // `day` is checked to not cross
                // Adjust the farthest day that might cross to `day - 1`.
                day_range = (day_range.0, day - 1);
            }
        }
        day_range.0 as i32
    }

    const MOVES: [(i32, i32); 4] = [(1, 0), (0, -1), (-1, 0), (0, 1)];
    const VISITED: i32 = -1;

    /// - Time complexity: O(row * col); build the matrix is O(row * col), depth-first search is also O(number of land), which is also O(row * col).
    /// - Space complexity: O(row * col).
    fn can_cross(row: usize, col: usize, waters: &[(usize, usize)]) -> bool {
        // NOTE: 1-based index
        let mut matrix = vec![vec![Self::LAND; col + 1]; row + 1];
        for &(r, c) in waters {
            matrix[r][c] = Self::WATER;
        }
        let mut stack = Vec::<(usize, usize)>::new();
        // The sources are the lands on the top row, the destinations are any land on the bottom row.
        // Start from the sources.
        for j in 1..=col {
            if matrix[1][j] == Self::LAND {
                stack.push((1, j));
            }
        }
        while let Some(land) = stack.pop() {
            for r#move in Self::MOVES {
                if let Some(next_land) = Self::move_to_land(land, r#move, &matrix) {
                    // Reach any of the destinations.
                    if next_land.0 == row {
                        return true;
                    }
                    matrix[next_land.0][next_land.1] = Self::VISITED;
                    stack.push(next_land);
                }
            }
        }
        false
    }

    /// Returns the moved cell if such cell is in the matrix and is a piece of land.
    /// - Time complexity: O(1)
    /// - Space complexity: O(1)
    fn move_to_land(
        cell: (usize, usize),
        offset: (i32, i32),
        matrix: &Vec<Vec<i32>>,
    ) -> Option<(usize, usize)> {
        if cell.0 == 1 && offset.0 == -1
            || cell.1 == 1 && offset.1 == -1
            || cell.0 == matrix.len() - 1 && offset.0 == 1
            || cell.1 == matrix[1].len() - 1 && offset.1 == 1
        {
            None
        } else {
            let next = (
                (cell.0 as i32 + offset.0) as usize,
                (cell.1 as i32 + offset.1) as usize,
            );
            if matrix[next.0][next.1] == Self::LAND {
                Some(next)
            } else {
                None
            }
        }
    }
}
