use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    /// Traverse level by level with breadth-first search.
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut queue = std::collections::LinkedList::<Rc<RefCell<TreeNode>>>::new();
        if let Some(root_) = &root {
            queue.push_back(Rc::clone(root_));
        }
        let mut level = 0;
        let mut max_sum = i32::MIN;
        let mut level_with_max_sum = 0;
        while !queue.is_empty() {
            level += 1;
            let num_of_nodes_in_level = queue.len();
            let mut sum = 0;
            for _ in 0..num_of_nodes_in_level {
                let node = queue.pop_front().unwrap();
                let node_ = node.borrow();
                sum += node_.val;
                if node_.left.is_some() {
                    queue.push_back(node_.left.clone().unwrap());
                }
                if node_.right.is_some() {
                    queue.push_back(node_.right.clone().unwrap());
                }
            }
            if sum > max_sum {
                max_sum = sum;
                level_with_max_sum = level;
            }
        }
        level_with_max_sum
    }
}
