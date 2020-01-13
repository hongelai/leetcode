/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) return;
        
        // find the last node of the first half
        ListNode fast, slow;
        fast = slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        
        //reverse second half
        fast = slow.next; // slow points to the last node of first half, fast points to the first node of second hafl
        while (fast != null && fast.next != null) {
            ListNode tmp = fast.next;
            fast.next = tmp.next;
            tmp.next = slow.next;
            slow.next = tmp;
        }
        
        // split and then merge
        fast = slow.next;
        slow.next = null;
        slow = head;
        
        while (fast != null) {
            ListNode tmp = fast;
            fast = fast.next;
            tmp.next = slow.next;
            slow.next = tmp;
            slow = slow.next.next;
        }
    }
}