/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    //divide and conquer
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;
        
        ListNode fast = head, slow = head;
        
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            if (fast != null) slow = slow.next; // use if() to handle 1->2->null
        }
        
        fast = slow.next;
        slow.next = null;
        
        ListNode l1 = sortList(head);
        ListNode l2 = sortList(fast);
        
        return merge(l1, l2);
    }
    
    private ListNode merge(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        if (l1.val < l2.val) {
            l1.next = merge(l1.next, l2);
            return l1;
        } else {
            l2.next = merge(l1, l2.next);
            return l2;
        }
    }
}