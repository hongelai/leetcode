/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;
        
        ListNode pre = head, post = pre.next;
        while(post != null) {
            if(pre.val != post.val) {
                pre.next = post;
                pre = post;
            }
            post = post.next;
        }
        pre.next = null;
        
        return head;
    }
}