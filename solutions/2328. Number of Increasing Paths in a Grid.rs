#[derive(Eq, Hash, PartialEq, Clone, Copy)]
struct Coordinate(usize, usize);

use std::collections::HashMap;
impl Solution {
    // 1. Use depth-first search to explore all possible paths.
    // 2. Use hash map to memo "start from (i, j), there are n count of paths",
    // so no path can be explored twice.
    // Time complexity: O(m * n);
    // Space complexity: O(m * n);
    // where m * n is the size of the grid.
    pub fn count_paths(grid: Vec<Vec<i32>>) -> i32 {
        let modulo = 1000000007;
        let mut path_counts = 0;
        let mut memo = HashMap::<Coordinate, u32 /* counts */>::new();
        // Each coordinate is a possible source.
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if !memo.contains_key(&Coordinate(i, j)) {
                    Self::find_increasing_paths_from(&grid, Coordinate(i, j), &mut memo);
                }
                path_counts = (path_counts + memo.get(&Coordinate(i, j)).unwrap()) % modulo;
            }
        }
        path_counts as i32
    }

    fn find_increasing_paths_from(
        grid: &Vec<Vec<i32>>,
        source: Coordinate,
        memo: &mut HashMap<Coordinate, u32>,
    ) {
        let modulo = 1000000007;
        let mut count = 1 /* source itself */;
        for neighbor in Self::get_in_grid_neighbors(grid, source) {
            // is increasing path
            if grid[source.0][source.1] < grid[neighbor.0][neighbor.1] {
                if !memo.contains_key(&neighbor) {
                    Self::find_increasing_paths_from(grid, neighbor, memo);
                }
                count = (count + *memo.get(&neighbor).unwrap()) % modulo;
            }
        }
        memo.insert(source, count);
    }

    fn get_in_grid_neighbors(grid: &Vec<Vec<i32>>, source: Coordinate) -> Vec<Coordinate> {
        let mut neighbor = Vec::new();
        if source.0 > 0 {
            neighbor.push(/* up */ Coordinate(source.0 - 1, source.1));
        }
        if source.0 < grid.len() - 1 {
            neighbor.push(/* down */ Coordinate(source.0 + 1, source.1));
        }
        if source.1 > 0 {
            neighbor.push(/* left */ Coordinate(source.0, source.1 - 1));
        }
        if source.1 < grid[source.0].len() - 1 {
            neighbor.push(/* right */ Coordinate(source.0, source.1 + 1));
        }
        neighbor
    }
}
