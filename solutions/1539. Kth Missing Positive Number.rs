impl Solution {
    pub fn find_kth_positive(arr: Vec<i32>, k: i32) -> i32 {
        let misses_before_arr_0: i32 = arr[0] - 1;
        if misses_before_arr_0 >= k {
            return k;
        }
        Self::find_kth_int(arr, k - misses_before_arr_0)
    }

    // Finds the kth missing consecutive integer.
    // Does not have to start with 1.
    // Using binary search to achieve O(log(n)).
    fn find_kth_int(arr: Vec<i32>, k: i32) -> i32 {
        if arr.len() == 1 {
            return arr[0] + k;
        }
        let half_len: usize = arr.len() / 2;
        let misses_between: i32 = arr[half_len] - arr[0] - half_len as i32;
        if misses_between >= k {
            return Self::find_kth_int(arr[0..half_len].to_vec(), k);
        }
        return Self::find_kth_int(arr[half_len..arr.len()].to_vec(), k - misses_between);
    }
}
