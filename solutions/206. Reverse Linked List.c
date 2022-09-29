/*
 * Main:
 *  3 pointers prev, curr and next. In each loop, curr points back to prev.
 *  Though curr no longer knows next, we already kept it, so no nodes are lost.
 * Boundaries:
 *  begin - the first prev is NULL, so the tail after reversed (head,
 *    originally) points to NULL properly.
 *  end - next are kept at the beginning of a loop. When head reaches the
 *    tail, we have one more to reverse, with next safely points to NULL;
 *    when prev reaches tail, head points to NULL, so the loop ends,
 *    no `NULL->next`.
 */
struct ListNode* reverseList(struct ListNode* head) {
  struct ListNode* prev = NULL;
  struct ListNode* curr = head;
  while (curr) {
    struct ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
