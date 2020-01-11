/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    // divider and conquer Time O(N.logK) Space O(1)
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;
        
        return mergeKLists(lists, 0, lists.length - 1);
    }
    
    public ListNode mergeKLists(ListNode[] lists, int s, int e) {
        if (e < s) {
            return null;
        }
        if (e - s == 0) return lists[s];
        if (e - s == 1) return mergeTwoLists(lists[s], lists[e]);
        
        int mid = (s + e) / 2;
        ListNode left = mergeKLists(lists, s, mid);
        ListNode right = mergeKLists(lists, mid + 1, e);
        return mergeTwoLists(left, right);
    }
    
    public ListNode mergeTwoLists(ListNode a, ListNode b) {
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        
        while(a != null && b!= null) {
            if (a.val < b.val) {
                cur.next = a;
                cur = cur.next;
                a = a.next;
            } else {
                cur.next = b;
                cur = cur.next;
                b = b.next;
            }
        }
        
        if (a != null) cur.next = a;
        else if (b != null) cur.next = b;
        
        return dummy.next;
    }
    
    /* Count occurrence of each node. Limit : count cannot exceed INT_MAX
      Time O(N), Space O(N)
     */
    public ListNode mergeKLists_2(ListNode[] lists) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        Map<Integer, Integer> map = new HashMap<>();

        for (ListNode head : lists) {
            while (head != null) {
                if (!map.containsKey(head.val)) {
                    min = Math.min(min, head.val);
                    max = Math.max(max, head.val);
                    map.put(head.val, 1);
                } else {
                    map.put(head.val, map.get(head.val) + 1);
                }
                head = head.next;
            }
        }

        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;

        for (int i = min; i <= max; i++) {
            if (map.get(i) == null) continue;;
            int counter = map.get(i);
            while (counter-- > 0) {
                cur.next = new ListNode (i);
                cur = cur.next;
            }
        }
        return dummy.next;
    }
    
    /*
       Time O(NlogK). Space O(k)
     */
    public ListNode mergeKLists_1(ListNode[] lists) {
        PriorityQueue<ListNode> queue = new PriorityQueue<>(Comparator.comparingInt((ListNode o) -> o.val));
        
        for (ListNode head : lists) {
            if (head != null) queue.add(head);
        }
        
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        
        /* always keep the k head node in queue
         * once remove one, push its next into queue.
         */
        while (!queue.isEmpty()) {
            ListNode node = queue.poll();
            cur.next = node;
            cur = cur.next;
            if (cur.next != null) queue.add(cur.next);
        }
        
        return dummy.next;
    }
}