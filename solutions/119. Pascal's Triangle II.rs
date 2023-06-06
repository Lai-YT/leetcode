impl Solution {
  pub fn get_row(row_index: i32) -> Vec<i32> {
      let mut row = vec![0; (row_index + 1) as usize];
      for i in 0..row_index + 1 {
          for j in (1..i).rev() {
              row[j as usize] = row[(j - 1) as usize] + row[j as usize];
          }
          row[0] = 1;
          row[i as usize] = 1;
      }
      row
  }
}
