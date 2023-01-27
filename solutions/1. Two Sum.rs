impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut nums_ = nums.to_owned();
        nums_.sort_unstable();

        use std::convert::TryInto;
        let mut head: usize = 0;
        let mut tail: usize = (nums_.len() - 1).try_into().unwrap();
        while head < tail {
            let sum = nums_[head] + nums_[tail];
            if sum == target {
                break;
            } else if sum < target {
                head += 1;
            } else {
                tail -= 1;
            }
        }

        // You may assume that each input would have exactly one solution,
        // and you may not use the same element twice.
        vec![
            nums.iter().position(|&x| x == nums_[head]).unwrap() as i32,
            nums.iter().rposition(|&x| x == nums_[tail]).unwrap() as i32,
        ]
    }
}
