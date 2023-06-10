use std::cmp::Ordering;

impl Solution {
    pub fn max_value(n: i32, index: i32, max_sum: i32) -> i32 {
        // the smallest possible value is 1, greatest is max_sum,
        // find the actual max value from the interval, using binary search
        let mut min = 1;
        let mut max = max_sum;
        let mut mid = (min + max) / 2;
        while min < max {
            match (Self::get_sum(n as i64, index as i64, mid as i64)).cmp(&(max_sum as i64)) {
                Ordering::Equal => {
                    return mid;
                }
                Ordering::Less => {
                    // mid may be the answer if we can't find any greater,
                    // so keep it as min
                    min = mid;
                }
                Ordering::Greater => {
                    // mid itself is never gonna be the answer, exclude it
                    max = mid - 1;
                }
            }
            mid = (min + max + 1/* so that we don't get stuck at min */) / 2;
        }
        // since we cannot find any greater than min, min is the max value
        min
    }

    /// Returns the smallest sum if we put `value` on the `index`.
    /// It's possible that the sum exceeds the limit of i32, so we use i64.
    fn get_sum(n: i64, index: i64, value: i64) -> i64 {
        let left_sum = if value >= index + 1 {
            // arithmetic progression from (value - index) to value,
            // (index + 1) numbers in total
            (value + (value - index)) * (index + 1) / 2
        } else {
            (value + 1) * value / 2 // arithmetic progression from 1 to value
                + ((index + 1) - value) * 1 // others are all 1s
        };
        let right_sum = if value >= (n - index) + 1 {
            // arithmetic progression from value to value - (n - index),
            // ((n - 1) - index + 1) numbers in total
            (value + (value - (n - (index + 1)))) * ((n - 1) - index + 1) / 2
        } else {
            (value + 1) * value / 2 // arithmetic progression from 1 to value
                + (((n - 1) - index + 1) - value) * 1 // others are all 1s
        };
        // value is counted twice
        left_sum + right_sum - value
    }
}
