impl Solution {
  pub fn transpose(matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
      let num_of_rows = matrix.len();
      let num_of_cols = matrix[0].len();
      let mut transposed_matrix = vec![vec![0; num_of_rows]; num_of_cols]; /* exchange row & col */
      for i in 0..num_of_rows {
          for j in 0..num_of_cols {
              transposed_matrix[j][i] = matrix[i][j];
          }
      }
      transposed_matrix
  }
}
