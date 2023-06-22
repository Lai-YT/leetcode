impl Solution {
  pub fn can_construct(ransom_note: String, magazine: String) -> bool {
      let mut letter_frequency_in_magazine = vec![0; 26 /* num of lowercase alphabets */];
      for &letter in magazine.as_bytes() {
          letter_frequency_in_magazine[Self::offset_with_a(letter)] += 1;
      }
      for &letter in ransom_note.as_bytes() {
          if letter_frequency_in_magazine[Self::offset_with_a(letter)] == 0 {
              return false;
          }
          letter_frequency_in_magazine[Self::offset_with_a(letter)] -= 1;
      }
      true
  }

  fn offset_with_a(letter: u8) -> usize {
      // a itself is 0, b is 1, and so on
      (letter - "a".as_bytes()[0]) as usize
  }
}
