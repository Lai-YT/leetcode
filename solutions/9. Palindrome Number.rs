impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 || (x % 10 == 0 && x != 0)
        /* the MSB of a number can't be 0 unless it's 0 */
        {
            return false;
        }

        /* only revert half of the number to prevent overflowing. */
        let mut upper_half: i32 = x;
        let mut lower_half: i32 = 0;
        while upper_half > lower_half {
            lower_half = lower_half * 10 + upper_half % 10;
            upper_half /= 10;
        }

        /* lower half would have one digit more than upper half if x has odd
        number of digits */
        return upper_half == lower_half || upper_half == lower_half / 10;
    }
}
