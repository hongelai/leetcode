/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    ArrayList<Integer> vals = new ArrayList<>();
    ListNode head;
    
    // Time O(n) Space O(logn)
    public TreeNode sortedListToBST(ListNode head) {
        int size = 0;
        for (ListNode cur = head; cur != null; cur = cur.next) {
            size++;
        }
        this.head = head; //Has to be global variable since Java is passed by ref
        return sortedListToBST(0, size-1);
    }
    
    //mimic inorder traveral and use mid to balance tree
    private TreeNode sortedListToBST(int l, int r) {
        if (l > r) return null;
        
        int mid = (l + r) / 2;
        TreeNode left = sortedListToBST(l, mid-1);
        
        TreeNode node = new TreeNode(head.val);
        node.left = left;
        head = head.next;
        
        node.right = sortedListToBST(mid+1, r);
        
        return node;
    }
    
    // Time O(n) Space O(n)
    public TreeNode sortedListToBST_1(ListNode head) {
        for (ListNode cur = head; cur != null; cur = cur.next) {
            vals.add(cur.val);
        }
        
        return sortedListToBST_1(0, vals.size()-1);
    }
    
    private TreeNode sortedListToBST_1(int s, int e) {
        if (s > e) return null;
        
        int mid = (s + e) / 2;
    
        TreeNode node = new TreeNode(vals.get(mid));
        node.left = sortedListToBST_1(s, mid-1);
        node.right = sortedListToBST_1(mid+1, e);
        
        return node;
    }
}