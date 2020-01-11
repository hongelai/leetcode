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
    List<List<Integer>> rs = new ArrayList<List<Integer>>();
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        preorder(root, new LinkedList<Integer>(), sum);
        return rs;
    }
    
    //Time O(n) Space O(logn)
    public void preorder(TreeNode root, LinkedList<Integer> item, int remain) {
        if (root == null) return;
        
        item.add(root.val);
        if (root.left == null && root.right == null) {
            if (remain == root.val) rs.add(new LinkedList<Integer>(item));
        }
        
        preorder(root.left, item, remain-root.val);
        preorder(root.right, item, remain-root.val);
        item.removeLast();
    }
}