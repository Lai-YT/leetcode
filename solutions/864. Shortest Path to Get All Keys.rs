use std::collections::{HashMap, HashSet, VecDeque};

#[derive(PartialEq, Eq)]
enum CellKind {
    Empty,
    Wall,
    Start,
    Key,
    Lock,
}

#[derive(Clone, Copy, PartialEq, Eq, Hash)]
struct Cell {
    i: usize,
    j: usize,
}

impl Cell {
    pub fn get_kind(&self, grid: &Vec<String>) -> CellKind {
        match grid[self.i].as_bytes()[self.j] {
            b'.' => CellKind::Empty,
            b'#' => CellKind::Wall,
            b'@' => CellKind::Start,
            b'a'..=b'z' => CellKind::Key,
            b'A'..=b'Z' => CellKind::Lock,
            _ => panic!(),
        }
    }

    /// Returns `None` if the cell is not in grid after moved.
    pub fn r#move(&self, offset: (i32, i32), grid: &Vec<String>) -> Option<Cell> {
        if offset.0 == -1 && self.i == 0
            || offset.1 == -1 && self.j == 0
            || offset.0 == 1 && self.i == grid.len() - 1
            || offset.1 == 1 && self.j == grid[0].len() - 1
        {
            None
        } else {
            Some(Cell {
                i: (self.i as i32 + offset.0) as usize,
                j: (self.j as i32 + offset.1) as usize,
            })
        }
    }
}

type KeyState = u32;

impl Solution {
    const MOVES: [(i32, i32); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

    pub fn shortest_path_all_keys(grid: Vec<String>) -> i32 {
        let start = Self::find_start(&grid);
        let all_keys = Self::find_all_keys(&grid);
        let mut queue = VecDeque::<(Cell, KeyState, i32 /* distance */)>::new();
        let mut visited = HashMap::<KeyState, HashSet<Cell>>::new();
        queue.push_back((start, 0, 0));
        visited.insert(0, HashSet::from([start]));

        while let Some((cell, key_state, dist)) = queue.pop_front() {
            for r#move in Self::MOVES {
                if let Some(next) = cell.r#move(r#move, &grid) {
                    let mut new_key_state = key_state;
                    match next.get_kind(&grid) {
                        CellKind::Wall => continue,             // cannot walk into
                        CellKind::Empty | CellKind::Start => {} // nothing other than walk into
                        CellKind::Key => {
                            let &key = &grid[next.i].as_bytes()[next.j];
                            let has_key = (new_key_state >> (key - b'a') & 1) == 1;
                            if !has_key {
                                // pick up
                                new_key_state |= 1 << (key - b'a');
                                if new_key_state == all_keys {
                                    return dist + 1;
                                }
                            }
                        }
                        CellKind::Lock => {
                            let &lock = &grid[next.i].as_bytes()[next.j];
                            let has_key = (new_key_state >> (lock - b'A') & 1) == 1;
                            if !has_key {
                                continue;
                            }
                        }
                    }
                    if !Self::is_visited(next, new_key_state, &visited) {
                        Self::walk_into(next, new_key_state, dist + 1, &mut visited, &mut queue);
                    }
                }
            }
        }
        -1
    }

    fn walk_into(
        cell: Cell,
        key_state: KeyState,
        dist: i32,
        visited: &mut HashMap<KeyState, HashSet<Cell>>,
        queue: &mut VecDeque<(Cell, KeyState, i32)>,
    ) {
        visited.entry(key_state).or_default().insert(cell);
        queue.push_back((cell, key_state, dist));
    }

    fn is_visited(
        cell: Cell,
        key_state: KeyState,
        visited: &HashMap<KeyState, HashSet<Cell>>,
    ) -> bool {
        visited.contains_key(&key_state) && visited.get(&key_state).unwrap().contains(&cell)
    }

    fn find_start(grid: &Vec<String>) -> Cell {
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if (Cell { i, j }).get_kind(&grid) == CellKind::Start {
                    return Cell { i, j };
                }
            }
        }
        panic!()
    }

    fn find_all_keys(grid: &Vec<String>) -> KeyState {
        let mut key_state = 0 as KeyState;
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if (Cell { i, j }).get_kind(&grid) == CellKind::Key {
                    let &key = &grid[i].as_bytes()[j];
                    key_state |= 1 << (key - b'a');
                }
            }
        }
        key_state
    }
}
