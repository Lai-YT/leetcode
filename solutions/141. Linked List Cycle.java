/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    private ListNode tortoise;
    private ListNode hare;
    private boolean hareReachedTail = false;
​
    /**
     * Using "tortoise and the hare algorithm" to achieve O(1) space complexity.
     * What a beautiful solution.
     *
     * The hare runs two times faster than the tortoise.
     * If there's a cycle, the hare will meet the tortoise.
     */
    public boolean hasCycle(ListNode head) {
        if (head == null) { return false; }
​
        tortoise = head;
        hare = head;
        do {
            hareRunTwoStep();
            tortoiseWalkOneStep();
            if (hareHasReachedTail()) {
                return false;
            }
        } while (!hareMeetTortoise());
        return true;
    }
​
    private boolean hareMeetTortoise() {
        return hare == tortoise;
    }
​
    private void hareRunTwoStep() {
        try {
            hare = hare.next;
            hare = hare.next;
        } catch (NullPointerException e) {
            hareReachedTail = true;
        }
    }
​
    private void tortoiseWalkOneStep() {
        tortoise = tortoise.next;
    }
​
    private boolean hareHasReachedTail() {
        return hareReachedTail;
    }
}
​
