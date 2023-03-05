// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        // An elegant solution from
        // https://leetcode.com/problems/swap-nodes-in-pairs/solutions/2882193/simple-rust-recursive-solution/?orderBy=most_votes&languageTags=rust.
        match head {
            Some(mut curr) => match curr.next {
                Some(mut next) => {
                    curr.next = Self::swap_pairs(next.next);
                    next.next = Some(curr);
                    Some(next)
                }
                None => Some(curr),
            },
            None => head,
        }
    }
}
