impl Solution {
    pub fn compress(chars: &mut Vec<char>) -> i32 {
        Self::add_sentinel(chars);
        let mut compressed_end: usize = 0;
        let mut count: u32 = 0;
        let mut prev_c: char = '\0';
        for i in 0..chars.len() {
            let c: char = chars[i];
            if c != prev_c && prev_c != '\0' {
                chars[compressed_end] = prev_c;
                compressed_end += 1;
                if Self::can_be_compressed(count) {
                    for d in count.to_string().chars() {
                        chars[compressed_end] = d;
                        compressed_end += 1;
                    }
                }
                count = 0;
            }
            count += 1;
            prev_c = c;
        }
        compressed_end as i32
    }

    fn add_sentinel(chars: &mut Vec<char>) {
        chars.push('\0')
    }

    fn can_be_compressed(count: u32) -> bool {
        count > 1
    }
}
