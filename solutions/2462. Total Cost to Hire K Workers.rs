#[derive(PartialEq, Eq, PartialOrd, Ord)]
enum Group {
    First,
    Second,
}

use std::{cmp::Reverse, collections::BinaryHeap};

type MinHeap<T> = BinaryHeap<Reverse<T>>;

impl Solution {
    pub fn total_cost(costs: Vec<i32>, k: i32, candidates: i32) -> i64 {
        // o o o o x x x o o o o (candidate = 4)
        //         ^   ^
        //         |   |
        //     next_1  next_2
        let mut next_first = candidates as usize;
        // NOTE: candidates may equal to costs.len(), which causes `next_second` to be -1 => overflow
        //  in such case, make `next_second` 0. Since `next_first` must be greater than 0, `has_two_groups` still holds as false.
        let mut next_second = if candidates as usize == costs.len() {
            0
        } else {
            costs.len() - 1 - candidates as usize
        };
        let mut heap = MinHeap::new();
        if Self::has_two_groups(next_first, next_second) {
            heap.extend(
                costs[0..candidates as usize]
                    .iter()
                    .map(|&c| Reverse((c, Group::First))),
            );
            heap.extend(
                costs[costs.len() - candidates as usize..]
                    .iter()
                    .map(|&c| Reverse((c, Group::Second))),
            );
        } else {
            heap.extend(costs.iter().map(|&c| Reverse((c, Group::First))));
        }
        let mut total_cost: i64 = 0;
        for _ in 0..k {
            let Reverse((next_minimum_cost, group)) = heap.pop().unwrap();
            total_cost += next_minimum_cost as i64;
            if Self::has_two_groups(next_first, next_second) {
                match group {
                    Group::First => {
                        heap.push(Reverse((costs[next_first], Group::First)));
                        next_first += 1;
                    }
                    Group::Second => {
                        heap.push(Reverse((costs[next_second], Group::Second)));
                        next_second -= 1;
                    }
                }
            }
        }
        total_cost
    }

    fn has_two_groups(next_first: usize, next_second: usize) -> bool {
        return next_first <= next_second;
    }
}
