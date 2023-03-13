impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        if source == destination {
            return true;
        }
        use std::collections::HashMap;
        use std::collections::VecDeque;
        // the original array structure is too inefficient on searching
        let mut neighbors_of_vertices: HashMap<i32, Vec<i32>> = HashMap::new();
        for edge in &edges {
            let u: i32 = edge[0];
            let v: i32 = edge[1];
            match neighbors_of_vertices.get_mut(&u) {
                Some(es) => es.push(v),
                None => {
                    neighbors_of_vertices.insert(u, vec![v]);
                }
            }
            match neighbors_of_vertices.get_mut(&v) {
                Some(es) => es.push(u),
                None => {
                    neighbors_of_vertices.insert(v, vec![u]);
                }
            }
        }

        let mut to_visit: VecDeque<i32> = VecDeque::new();
        let mut visited: Vec<bool> = vec![false; n as usize];
        to_visit.push_back(source);
        while !to_visit.is_empty() {
            // it's already checked by the loop condition
            let vertex: i32 = to_visit.pop_front().unwrap();
            if let Some(neighbors) = neighbors_of_vertices.get(&vertex) {
                for neighbor in neighbors {
                    if *neighbor == destination {
                        return true;
                    }
                    if !visited[*neighbor as usize] {
                        visited[*neighbor as usize] = true;
                        to_visit.push_back(*neighbor);
                    }
                }
            }
        }
        false
    }
}
