/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode small = new ListNode(-1);
        ListNode large = new ListNode(-1);
        
        ListNode first = small, second = large, cur = head;
        while (cur != null) {
            if (cur.val < x) {
                first.next = cur;
                first = first.next;
            } else {
                second.next = cur;
                second = second.next;
            }
            cur = cur.next;
        }
        second.next = null;
        first.next = large.next;
        return small.next;
    }
}