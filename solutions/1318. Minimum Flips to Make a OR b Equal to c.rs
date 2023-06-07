impl Solution {
  // 0 | 0 = 0, 0 | 1 = 1, 1 | 1 = 1
  // (1) want 1...
  //      get 0 0: flip either one => +1
  //      get 0 1: no flip         => +0
  //      get 1 0: no flip         => +0
  //      get 1 1: no flip         => +0
  //      which is 1 only if both bits are 0
  // (2) want 0...
  //      get 0 0: no flip         => +0
  //      get 0 1: flip 1          => +1
  //      get 1 0: flip 1          => +1
  //      get 1 1: flip both       => +2
  //      which is the number of 1s
  pub fn min_flips(a: i32, b: i32, c: i32) -> i32 {
      let mut flip_count = 0;
      for i in 0..i32::BITS {
          let ith_bit_of_c = (c >> i) & 1;
          let ith_bit_of_a = (a >> i) & 1;
          let ith_bit_of_b = (b >> i) & 1;
          flip_count += match ith_bit_of_c {
              1 => {
                  if ith_bit_of_a == 0 && ith_bit_of_b == 0 {
                      1
                  } else {
                      0
                  }
              }
              0 => ith_bit_of_a + ith_bit_of_b,
              _ => unreachable!(),
          };
      }
      flip_count
  }
}
