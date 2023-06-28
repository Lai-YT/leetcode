use std::{collections::BinaryHeap, vec};

/// A simple wrapper for f64 to be orderable.
/// Not dealing with inf and NaN.
#[derive(Clone, Copy, PartialEq, PartialOrd)]
struct F64(f64);

/// We won't use Eq, but required to be implemented for Ord.
impl Eq for F64 {}
impl Ord for F64 {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.partial_cmp(other).unwrap()
    }
}

impl Solution {
    pub fn max_probability(
        n: i32,
        edges: Vec<Vec<i32>>,
        succ_prob: Vec<f64>,
        start: i32,
        end: i32,
    ) -> f64 {
        // they are indices, shadow with type usize
        let n = n as usize;
        let start = start as usize;
        let end = end as usize;

        let mut neighbors = vec![Vec::<(usize, f64)>::new(); n];
        for i in 0..edges.len() {
            // undirected, two way
            neighbors[edges[i][0] as usize].push((edges[i][1] as usize, succ_prob[i].log2()));
            neighbors[edges[i][1] as usize].push((edges[i][0] as usize, succ_prob[i].log2()));
        }

        // distance from start to end, in log(prob)
        // NOTE: since multiplying probabilities will result in precision errors,
        // we take log to convert multiplication into addition.
        // Also we'll be using MaxHeap to always take the greatest probability (1 is the greatest,
        // with it's log value being 0, otherwise have negative log values).
        let mut dist = vec![f64::MIN; n];
        dist[start] = 1f64.log2();
        let mut max_heap = BinaryHeap::<(F64, usize)>::new();

        max_heap.push((F64(dist[start]), start));
        while !max_heap.is_empty() {
            let (_, node) = max_heap.pop().unwrap();
            if node == end {
                return 2f64.powf(dist[end]); // resolve the logarithm
            }
            for &(neighbor, prob) in &neighbors[node] {
                let alt = dist[node] + prob;
                if alt > dist[neighbor] {
                    dist[neighbor] = alt;
                    // it's okay that a node may be push multiple time since they
                    // always yield lower probability, thus not effecting the relaxation
                    max_heap.push((F64(dist[neighbor]), neighbor));
                }
            }
        }
        0.0 // cannot reach
    }
}
