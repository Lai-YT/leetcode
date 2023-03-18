impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        for i in 0..haystack.len() {
            if i + needle.len() > haystack.len() {
                break;
            }
            if haystack[i..i + needle.len()].eq(&needle) {
                return i as i32;
            }
        }
        -1
    }
}
