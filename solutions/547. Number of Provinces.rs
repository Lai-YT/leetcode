struct UnionFind {
  num_of_disjoint_sets: usize,
  roots: Vec<usize>,
  ranks: Vec<usize>,
}

impl Solution {
  pub fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {
      let mut union_find = UnionFind::new(is_connected.len());
      for i in 0..is_connected.len() {
          for j in 0..is_connected[0].len() {
              if is_connected[i][j] == 1 {
                  union_find.union(i, j);
              }
          }
      }
      union_find.num_of_disjoint_sets() as i32
  }
}

impl UnionFind {
  pub fn new(size: usize) -> Self {
      Self {
          num_of_disjoint_sets: size,
          // initialize the root as the node itself
          roots: (0..size).collect(),
          ranks: vec![1 /* starts with rank 1 */; size],
      }
  }

  pub fn num_of_disjoint_sets(&self) -> usize {
      self.num_of_disjoint_sets
  }

  pub fn is_connected(&mut self, a: usize, b: usize) -> bool {
      self.find(a) == self.find(b)
  }

  /// O(1) amortized. Optimized with union by rank.
  pub fn union(&mut self, a: usize, b: usize) {
      let root_a = self.find(a);
      let root_b = self.find(b);
      if root_a != root_b {
          self.num_of_disjoint_sets -= 1;
          if self.ranks[root_a] > self.ranks[root_b] {
              self.roots[root_b] = root_a;
          } else if self.ranks[root_a] < self.ranks[root_b] {
              self.roots[root_a] = root_b;
          } else {
              // choose root_a as the root, never mind
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
