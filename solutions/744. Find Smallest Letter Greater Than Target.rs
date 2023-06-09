impl Solution {
  pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
      let idx_of_smallest_greater = letters.partition_point(|letter| *letter <= target);
      if idx_of_smallest_greater == letters.len() {
          letters[0]
      } else {
          letters[idx_of_smallest_greater]
      }
  }
}
