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
        ListNode newHead = new ListNode(-1);
        
        //take the head from old list and insert into head of new list
        while (head != null) {
            ListNode remain = head.next;
            
            head.next = newHead.next;
            newHead.next = head;
            head = remain;
        }
        
        return newHead.next;
    }
}
}
