/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre, post;
        pre = dummy;
        post = dummy.next;
        
        while (post != null) {
            if (post.val == val) {
                pre.next = post.next;
                post = post.next;
            } else {
                pre = post;
                post = post.next;
            }
        }
        return dummy.next;
    }
}