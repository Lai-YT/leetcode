impl Solution {
  pub fn longest_common_prefix(strs: Vec<String>) -> String {
      if strs.is_empty() {
          return String::from("");
      }

      let mut bytes: Vec<&[u8]> = Vec::new();
      for str in &strs {
          bytes.push(str.as_bytes());
      }

      for i in 0..strs[0].len() {
          let match_: u8 = bytes[0][i];
          for byte in &bytes {
              if i == byte.len() || byte[i] != match_ {
                  return String::from_utf8(bytes[0][..i].to_vec()).unwrap();
              }
          }
      }
      strs[0].to_owned()
  }
}
