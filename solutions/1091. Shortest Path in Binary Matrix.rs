impl Solution {
    pub fn shortest_path_binary_matrix(mut grid: Vec<Vec<i32>>) -> i32 {
        let start = (0, 0);
        let end = (grid.len() - 1, grid[0].len() - 1);
        if grid[0][0] != 0 {
            return -1;
        }
        let mut queue = std::collections::VecDeque::<(usize, usize)>::new();
        queue.push_back(start);
        let directions: [(i32, i32); 8] = [
            (1, 1),
            (0, 1),
            (-1, 1),
            (-1, 0),
            (-1, -1),
            (0, -1),
            (1, -1),
            (1, 0),
        ];
        let mut length = 0;
        while !queue.is_empty() {
            length += 1;
            let reachable_in_length = queue.len();
            for _ in 0..reachable_in_length {
                let cell = queue.pop_front().unwrap();
                if cell == end {
                    return length;
                }
                for dir in directions {
                    // if in grid
                    if 0 <= (cell.0 as i32 + dir.0)
                        && (cell.0 as i32 + dir.0) < grid[0].len() as i32
                        && 0 <= (cell.1 as i32 + dir.1)
                        && (cell.1 as i32 + dir.1) < grid.len() as i32
                    {
                        let next = (cell.0 + dir.0 as usize, cell.1 + dir.1 as usize);
                        if grid[next.0][next.1] == 0 {
                            queue.push_back(next);
                            // As https://leetcode.com/problems/shortest-path-in-binary-matrix/solutions/312827/python-concise-bfs/comments/472495 suggested:
                            // For BFS, you need to mark a node the first time you 'see' it
                            // instead of when you 'visit' it.
                            // That's the reason we set grid[x][y] = 1 instead of wait and set grid[i][j] = 1.
                            // The reason is, if C is neighboring to A and B, when we visit A, we
                            // will put C to the queue. If we didn't mark C here, next time when we
                            // visit B, we will put C again to the queue. There could be quite a lot
                            // redundant search and lead to the TLE.
                            // DFS is another story as we will visit C before B.
                            grid[next.0][next.1] = 1;
                        }
                    }
                }
            }
        }
        -1
    }
}
