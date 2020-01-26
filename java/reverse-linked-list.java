/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode dummy = new ListNode(-1);
        
        if (head == null || head.next == null) return head;
        dummy.next = head;
        ListNode cur = head;
        
        while (cur != null && cur.next != null) {
            ListNode node = cur.next;
            
            cur.next = node.next;
            node.next = dummy.next;
            dummy.next = node;
        }
        
        return dummy.next;
    }
}