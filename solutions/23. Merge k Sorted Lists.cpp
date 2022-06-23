/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
​
struct Greater {
    bool operator() (ListNode* l, ListNode* r) {
        return l->val >= r->val;
    }
};
​
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Greater> min_heap{};
        for (ListNode* list : lists) {
            if (list) {
                min_heap.push(list);            
            }
        }
        
        ListNode* new_head = new ListNode{};
        ListNode* new_curr = new_head;
        while (!min_heap.empty()) {
            new_curr->next = min_heap.top();
            min_heap.pop();
            new_curr = new_curr->next;
            if (new_curr->next)  {
                min_heap.push(new_curr->next);
            }
