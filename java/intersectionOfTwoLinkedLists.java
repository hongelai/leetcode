/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA, b = headB;
        //if a & b have different len, then we will stop the loop after second iteration
        while (a != b) {
            /*
             In the first iteration, we will reset the pointer of one linkedlist to the head of another linkedlist after it reaches the tail node. In the second iteration, we will move two pointers until they points to the same node. Our operations in first iteration will help us counteract the difference. So if two linkedlist intersects, the meeting point in second iteration must be the intersection point. If the two linked lists have no intersection at all, then the meeting pointer in second iteration must be the tail node of both lists, which is null
            */
            a = a == null? headB : a.next;
            b = b == null? headA : b.next;
        }
        return a;
    }
    public ListNode getIntersectionNode1(ListNode headA, ListNode headB) {
        int lenA = 0, lenB = 0;
        ListNode a = headA, b = headB;
        while (a != null) {
            a = a.next;
            lenA++;
        }
        while (b != null) {
            b = b.next;
            lenB++;
        }
        int diff = Math.abs(lenA - lenB);
        if (lenA > lenB) {
            while (diff-- > 0) {
                headA = headA.next;
            }
        } else {
            while (diff-- > 0) {
                headB = headB.next;
            }
        }
        
        while (headA != null && headB != null) {
            if (headA == headB) return headA;
            else {
                headA = headA.next;
                headB = headB.next;
            }
        }
        return null;
    }
}