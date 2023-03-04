impl Solution {
    // Quick Sort + pivot selection with "Middle-of-Three"
    // Worst Case: time O(n*log(n)) / space O(log(n))
    // Note: the overhead of "Median-of-Medians" made it impractical
    // (https://en.wikipedia.org/wiki/Quicksort#Selection-based_pivoting)
    pub fn sort_array(nums: Vec<i32>) -> Vec<i32> {
        let mut nums_: Vec<i32> = nums.to_owned();
        Self::sort_partial_array(&mut nums_, 0, nums.len());
        nums_
    }

    fn sort_partial_array(nums: &mut Vec<i32>, begin: usize, end: usize) {
        if begin == end {
            return;
        }
        let i: usize = Self::partition(nums, begin, end);
        Self::sort_partial_array(nums, begin, i);
        Self::sort_partial_array(nums, i + 1, end);
    }

    fn partition(nums: &mut Vec<i32>, begin: usize, end: usize) -> usize {
        let p: usize = Self::middle_of_three(nums, begin, end);
        let pivot: usize = end - 1;
        // put pivot to the right most, then apply the Lomuto Partition Scheme
        nums.swap(p, pivot);
        let mut edge: usize = begin;
        for i in begin..end {
            if nums[i] < nums[pivot] {
                nums.swap(i, edge);
                edge = edge + 1;
            }
        }
        nums.swap(pivot, edge);
        edge
    }

    fn middle_of_three(nums: &Vec<i32>, begin: usize, end: usize) -> usize {
        let middle = (begin + end) / 2;
        let a = nums[begin];
        let b = nums[middle];
        let c = nums[end - 1];

        // middle => not greater than the other two at the same time
        if (a > b) ^ (a > c) {
            return begin;
        }
        if (b > a) ^ (b > c) {
            return middle;
        }
        end - 1
    }
}
