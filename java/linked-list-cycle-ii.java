/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    /* y 为相遇时慢指针在环上走过的距离
       -> x + (y + z) * n + y = 2 * (x + y)
       -> (y+z) * n - y = x 
       所以相遇后，让一个指针从起点重新走x的路程，另外一个指针会在环上走n圈，并停在-y的地方，即在交叉点相遇
    */
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) return null;
        
        ListNode fast = head, slow = head;
        
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            
            if (fast == slow) {//find cycle
                fast = head;
                while (slow != fast) {
                    slow = slow.next;
                    fast = fast.next;
                }
                
                return slow;
            }
        }
        
        return null;
    }
}