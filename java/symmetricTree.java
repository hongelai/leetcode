/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isSymmetric1(TreeNode root) {
        return root != null? solve(root.left, root.right) : true;
    }
    boolean solve(TreeNode left, TreeNode right) {
        if (left == null && right == null) return true;
        if (left == null || right == null) return false;
        return left.val == right.val && solve(left.left, right.right) && solve(left.right, right.left);
    }
    
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        if (root.left == null && root.right == null) return true;
        if (root.left == null || root.right == null) return false;
        
        LinkedList<TreeNode> Q = new LinkedList<TreeNode>();
        Q.offer(root.left);
        Q.offer(root.right);
        
        while(!Q.isEmpty()) {
            TreeNode n1 = Q.poll();
            TreeNode n2 = Q.poll();
            if (n1 == null && n2 == null) continue;
            if (n1 == null || n2 == null) return false;
            if (n1.val != n2.val) return false;
            Q.offer(n1.left);
            Q.offer(n2.right);
            Q.offer(n1.right);
            Q.offer(n2.left);
        }
        return true;
    }
}