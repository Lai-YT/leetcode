impl Solution {
  pub fn equal_pairs(grid: Vec<Vec<i32>>) -> i32 {
      // record all the rows
      let mut rows_seen = std::collections::HashMap::<Vec<i32>, i32>::new();
      for row in grid.iter() {
          *rows_seen.entry(row.clone()).or_insert(0) += 1;
      }

      // check the columns
      let mut count = 0;
      for j in 0..grid[0].len() {
          let col = Self::get_column(&grid, j);
          if let Some(frequency) = rows_seen.get(&col) {
              count += frequency;
          }
      }
      count
  }

  fn get_column(grid: &Vec<Vec<i32>>, col_no: usize) -> Vec<i32> {
      let mut col = Vec::with_capacity(grid.len());
      for i in 0..grid.len() {
          col.push(grid[i][col_no]);
      }
      col
  }
}
