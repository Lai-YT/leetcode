impl Solution {
  pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
      // The fast pointer is gonna run with 2 times faster than slow,
      // so when fast cannot take any progress, slow is at the middle.
      let mut slow = &head;
      let mut fast = &head;
      while fast.is_some() && fast.as_ref().unwrap().next.is_some() {
          slow = &slow.as_ref().unwrap().next;
          fast = &fast.as_ref().unwrap().next.as_ref().unwrap().next;
      }
      slow.clone()
  }
}
