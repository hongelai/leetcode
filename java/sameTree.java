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
    public boolean isSameTree1(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;
        return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;
        LinkedList<TreeNode> Q = new LinkedList<TreeNode>();
        Q.offer(p);
        Q.offer(q);
        while(!Q.isEmpty()) {
            TreeNode n1 = Q.poll();
            TreeNode n2 = Q.poll();
            if (n1 == null && n2 == null) continue;
            if (n1 == null || n2 == null) return false;
            if (n1.val != n2.val) return false;
            Q.offer(n1.left);
            Q.offer(n2.left);
            Q.offer(n1.right);
            Q.offer(n2.right);
        }
        return true;
    }
}