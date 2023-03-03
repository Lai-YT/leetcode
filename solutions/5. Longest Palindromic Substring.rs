use std::cmp;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let chars: Vec<char> = s.chars().collect();

        let mut max_begin: usize = 0;
        let mut max_end: usize = 0; // inclusive
        for i in 0..chars.len() {
            let len = cmp::max(
                Self::expand_around_center(&chars, i, i), // single centered
                Self::expand_around_center(&chars, i, i + 1), // dual centered
            );
            if len > max_end - max_begin + 1 {
                //  Single centered palindrome has odd length, taking floor on
                // (len - 1) / 2 and len / 2 are the same; dual centered palindrome
                // has even length. Since i is the left center, len has to be minused.
                max_begin = i - (len - 1) / 2;

                max_end = i + len / 2;
            }
        }

        chars[max_begin..=max_end].into_iter().collect()
    }

    fn expand_around_center(chars: &Vec<char>, mut left: usize, mut right: usize) -> usize {
        if right >= chars.len() {
            return 0;  // edge case
        }
        // be careful not to have usize overflow
        loop {
            if chars[left] != chars[right] {
                return (right - 1) - (left + 1) + 1; // restore the last in/decrement
            }
            if left == 0 || right == chars.len() - 1 {
                return right - left + 1;
            }
            left -= 1;
            right += 1;
        }
    }
}
