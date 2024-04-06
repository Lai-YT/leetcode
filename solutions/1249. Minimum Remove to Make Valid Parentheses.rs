impl Solution {
    // For details, see
    // https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/solutions/663204/super-simple-python-solution-with-explanation-faster-than-100-memory-usage-less-than-100.
    pub fn min_remove_to_make_valid(s: String) -> String {
        let mut idx_of_open = vec![];
        let mut is_removed = vec![false; s.len()];
        s.chars().enumerate().for_each(|(i, c)| {
            if c == '(' {
                idx_of_open.push(i);
            } else if c == ')' {
                if !idx_of_open.is_empty() {
                    idx_of_open.pop();
                } else {
                    is_removed[i] = true;
                }
            }
            // Al others are kept.
        });
        // Remove unmatched open parentheses.
        idx_of_open.iter().for_each(|i| is_removed[*i] = true);
        // Collect those to kepts as the result.
        s.chars()
            .enumerate()
            .filter_map(|(i, c)| match is_removed[i] {
                false => Some(c),
                true => None,
            })
            .collect()
    }
}
