impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        for i in (0..digits.len()).rev() {
            digits[i] += 1;
            if digits[i] == 10 {
                // has carry, keep next iteration
                digits[i] = 0;
            } else {
                // no carry, remaining digits preserved
                return digits;
            }
        }
        // still has carry, otherwise already returned inside the loop
        digits.insert(0, 1);
        digits
    }
}
