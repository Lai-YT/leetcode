/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
  // make the initial case not special
  struct ListNode sent = {.val = 0, .next = head};

  struct ListNode* prev = &sent;
  struct ListNode* curr = prev->next;

  /*
   * In each loop,
   * Initial:
   *    0 1 2 3 ...
   *  prev: 0
   *  curr: 1
   * End:
   *    0 2 1 3 ...
   *  prev: 1
   *  curr: 3
   */
  while (curr && curr->next) {
    prev->next = curr->next;        // 0 -> 2
    curr->next = curr->next->next;  // 1 -> 3
    prev->next->next = curr;        // 2 -> 1

    prev = curr;        // 0 = 1
    curr = curr->next;  // 1 == 3
  }

  return sent.next;
}
