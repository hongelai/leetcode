/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy.next, post = dummy;
        
        while(pre != null && pre.next != null) {
            //swap node
            ListNode tmp = pre.next;
            pre.next = pre.next.next;
            post.next = tmp;
            tmp.next = pre;
            
            //move forard
            post = pre;
            pre = pre.next;
        }
        return dummy.next;
    }
}