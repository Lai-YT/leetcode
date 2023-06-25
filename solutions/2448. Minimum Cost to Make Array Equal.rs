impl Solution {
    pub fn min_cost(nums: Vec<i32>, cost: Vec<i32>) -> i64 {
        // Finding the sort permutation:
        //  To sort two vectors base on the value of the first vector,
        //  use an additional vector to represent the indices, and sort those
        //  indices by the value of the first vector.
        //  So now using this extra layer of mapping, the two vectors are sorted in the same permutation.
        let mut indices: Vec<usize> = (0..nums.len()).collect();
        indices.sort_by(|&i, &j| nums[i].cmp(&nums[j]));
        // NOTE: The prefix_cost is already in the mapped order, so no more mapped required.
        let prefix_cost: Vec<i64> = indices
            .iter()
            .scan(0i64, |state, &i| {
                *state += cost[i] as i64;
                Some(*state)
            })
            .collect();
        // Try making all numbers equal to nums[i].
        // i = 0 is the initial case, build the total cost
        let mut total_cost = indices[1..].iter().fold(0i64, |acc, &i| {
            acc + i64::from(cost[i]) * i64::from(nums[i] - nums[indices[0]])
        });
        let mut min_cost = total_cost;
        // Then i = 1, 2, ...
        // The cost difference is made by the change of two parts:
        //  a. prefix sum of costs
        //  b. suffix sum of costs
        for i in 1..indices.len() {
            let gap = i64::from(nums[indices[i]] - nums[indices[i - 1]]);
            total_cost += prefix_cost[i - 1] * gap;
            let suffix_cost = prefix_cost[indices.len() - 1] - prefix_cost[i - 1];
            total_cost -= suffix_cost * gap;
            min_cost = min_cost.min(total_cost);
        }
        min_cost
    }
}
