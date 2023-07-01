impl Solution {
    pub fn convert_to_base7(num: i32) -> String {
        let mut num = num; // just to make it mutable
        let mut numeral_res = 0;
        let mut base = 1;
        while num != 0 {
            // The real base is 7, but to put it to the correct digit,
            // we have to treat it again like a decimal.
            // The sign is handled naturally.
            numeral_res += (num % 7) * base;
            num /= 7;
            base *= 10;
        }
        numeral_res.to_string()
    }
}
