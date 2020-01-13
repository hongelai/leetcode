/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    /*create a new list and insert nodes from old list to new list*/
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(-1), cur; 
        
        while (head != null) {
            cur = dummy;
            while (cur.next != null && cur.next.val < head.val) cur = cur.next;
            
            ListNode node = head;
            head = head.next;
            node.next = cur.next;
            cur.next = node;
        }
        
        return dummy.next;
    }
}