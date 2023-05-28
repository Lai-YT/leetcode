struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
  struct ListNode *ap = headA;
  struct ListNode *bp = headB;
  // Let say the length of list A and list b is al + common and bl + common, respectively.
  // If al != bl, ap will run al + common + bl and bp will run bl + common + al,
  // which make them reach at the intersection in the second iteration.
  // Note that common = 0 isn't a special case, just that the intersection node is NULL.
  while (ap != bp) {
    ap = ap ? ap->next : headB;
    bp = bp ? bp->next : headA;
  }
  return ap;
}
