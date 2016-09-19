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
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }
    
    public int maxDepth1(TreeNode root) {
        Queue<TreeNode> Q = new LinkedList<TreeNode>();
        int level = 0;
        if (root == null) return level;
        Q.offer(root);
        Q.offer(null);
        level++;
        
        while(!Q.isEmpty()) {
            TreeNode node = Q.poll();
            if (node != null) {
                if (node.left != null) Q.offer(node.left);
                if (node.right != null) Q.offer(node.right);
            } else {
                if (!Q.isEmpty()) {
                    level++;
                    Q.offer(null);
                }
            }
        }
        return level;
    }
}