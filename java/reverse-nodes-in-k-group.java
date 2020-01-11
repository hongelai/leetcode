/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy, cur = head;
        
        // cur must stop at the last node of the target swap group
        // otherwise it will not be able to handle pre -> 1-> 2 -> null with k =2
        for (int i = 1; cur != null;  i++) {
            if (i % k == 0) {
                pre = reverseOneGroup(pre, cur.next);
                cur = pre.next;
            } else {
                cur = cur.next;
            }
        }
        return dummy.next;
    }
    
    /*pre : points to the pre node of the target swap group
      next : points to the next node of the target swap group
      last : always points to the last node of the after-swap group
     */
    public ListNode reverseOneGroup(ListNode pre, ListNode next) {
        ListNode last = pre.next, cur = last.next;
        
        while (cur != next) {
            last.next = cur.next;
            cur.next = pre.next;
            pre.next = cur;
            cur = last.next;
        }
        return last;
    }
}   