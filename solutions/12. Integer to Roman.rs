impl Solution {
  pub fn int_to_roman(mut num: i32) -> String {
      let base_and_symbols = [
          (1000, "M"),
          (900, "CM"),
          (500, "D"),
          (400, "CD"),
          (100, "C"),
          (90, "XC"),
          (50, "L"),
          (40, "XL"),
          (10, "X"),
          (9, "IX"),
          (5, "V"),
          (4, "IV"),
          (1, "I"),
      ];
      base_and_symbols
          .iter()
          .map(|(base, symbol)| {
              let t = (num / base) as usize;
              num %= base;
              symbol.repeat(t)
          })
          .fold(String::new(), |res, s| res + &s)
  }
}
