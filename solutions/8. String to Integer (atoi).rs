impl Solution {
  pub fn my_atoi(s: String) -> i32 {
      let chars = s.chars().collect::<Vec<char>>();
      let mut remaining_chars = &chars[..];
      Self::skip_whitespace(&mut remaining_chars);
      let sign: i32 = match Self::get_sign(&mut remaining_chars) {
          Some('+') => 1,
          Some('-') => -1,
          Some(_) => unreachable!(),
          None => {
              if remaining_chars.is_empty() {
                  return 0;
              } else {
                  1
              }
          }
      };
      remaining_chars
          .iter()
          .map(|c| c.to_digit(10))
          .take_while(Option::is_some) // stops when ever we get a false
          .flatten()
          .fold(0, |acc: i32, digit: u32| {
              acc.saturating_mul(10).saturating_add(digit as i32 * sign)
          })
  }

  /// Consumes the leading `' '`s from `s`.
  fn skip_whitespace(s: &mut &[char]) {
      let mut i = 0;
      while i < s.len() {
          if s[i] != ' ' {
              break;
          }
          i += 1;
      }
      *s = &s[i..];
  }

  /// If there an explicit leading sign in `s`, consume the sign and return it..
  fn get_sign(s: &mut &[char]) -> Option<char> {
      if let Some(first) = s.first() {
          match first {
              &sign @ ('+' | '-') => {
                  *s = &s[1..];
                  Some(sign)
              }
              _ => None,
          }
      } else {
          None
      }
  }
}
