impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        // Using Heron's method.
        // See https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Heron%27s_method.

        let mut est = x as f64;
        let mut error = Self::error_between_root(x as f64, est);
        // precise to the integer part
        while (est + error) as i32 != est as i32 {
            est += error;
            error = Self::error_between_root(x as f64, est);
        }
        est as i32
    }

    fn error_between_root(x: f64, est: f64) -> f64 {
        (x - est * est) / (2.0 * est)
    }
}
