/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) return head;
        
        int len = 0;
        ListNode fast = head, slow = head;
        while (fast != null) {
            fast = fast.next;
            len++;
        }
        
        k = k%len;
        fast = head;
        
        for (int i = 0; i < k; i++) {
            fast = fast.next;
        }
        
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        
        fast.next = head;
        head = slow.next;
        slow.next = null;
        
        
        return head;
        
    }
}