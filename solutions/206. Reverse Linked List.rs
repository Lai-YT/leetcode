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
  pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
      let mut rev_head: Option<Box<ListNode>> = None;
      let mut opt_curr: Option<Box<ListNode>> = head;
      while let Some(mut curr) = opt_curr {
          opt_curr = curr.next;
          curr.next = rev_head;
          rev_head = Some(curr);
      }
      rev_head
  }
}
