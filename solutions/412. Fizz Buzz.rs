impl Solution {
  pub fn fizz_buzz(n: i32) -> Vec<String> {
      (1..=n)
          .into_iter()
          .map(|i| match (i % 3 == 0, i % 5 == 0) {
              (true, true) => "FizzBuzz".to_string(),
              (true, false) => "Fizz".to_string(),
              (false, true) => "Buzz".to_string(),
              _ => i.to_string(),
          })
          .collect()
  }
}
