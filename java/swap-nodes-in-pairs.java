/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        ListNode slow = dummy, fast = head;
        dummy.next = head;
        
        while (fast != null && fast.next != null) {
            slow.next = fast.next;
            fast.next = fast.next.next;
            slow.next.next = fast;
            
            //move forward
            slow = slow.next.next;
            fast = fast.next;
        }
        
        return dummy.next;   
    }
}