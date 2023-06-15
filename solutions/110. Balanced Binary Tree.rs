use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::is_balanced_and_get_height(root).0
    }

    /// Calculates the height and records whether the tree is balanced along the way.
    /// It would be O(n^2) if we calculate height & balance or not separately
    /// since there are duplicate traversals, unless some dynamic programming tricks are applied.
    fn is_balanced_and_get_height(root: Option<Rc<RefCell<TreeNode>>>) -> (bool, i32) {
        if let Some(ref root_) = root {
            let (left_is_balanced, left_height) =
                Self::is_balanced_and_get_height(root_.borrow().left.clone());
            let (right_is_balanced, right_height) =
                Self::is_balanced_and_get_height(root_.borrow().right.clone());
            (
                left_is_balanced && right_is_balanced && (left_height - right_height).abs() <= 1,
                1 + left_height.max(right_height),
            )
        } else {
            (true, -1)
        }
    }
}
