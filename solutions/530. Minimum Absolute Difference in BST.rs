// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn get_minimum_difference(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        // in-order traversal
        let mut nums = Vec::<i32>::new();
        let mut stack = std::collections::LinkedList::<Rc<RefCell<TreeNode>>>::new();
        let mut curr = root;
        while curr.is_some() || !stack.is_empty() {
            if let Some(curr_) = curr {
                stack.push_front(Rc::clone(&curr_));
                curr = curr_.borrow().left.clone();
            } else {
                let parent = stack.pop_front().unwrap();
                nums.push(parent.borrow_mut().val);
                curr = parent.borrow().right.clone();
            }
        }
        let mut min = i32::MAX;
        for i in 0..nums.len() - 1 {
            min = min.min((nums[i + 1] - nums[i]).abs());
        }
        min
    }
}
