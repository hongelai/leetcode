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
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 1;
        int left = Integer.MAX_VALUE, right = Integer.MAX_VALUE;
        if (root.left != null) left = minDepth(root.left);
        if (root.right != null) right = minDepth(root.right);
        return Math.min(left, right) + 1;
    }
    
    public int minDepth1(TreeNode root) {
        //level traverse
        if (root == null) return 0;
        Queue<TreeNode> Q = new LinkedList<TreeNode>();
        Q.offer(root);
        Q.offer(null);
        int level = 1;
        
        while (!Q.isEmpty()) {
            TreeNode node = Q.poll();
            if (node != null) {
                if(node.left == null && node.right == null) {//leaf node
                    return level;
                } 
                if (node.left != null) Q.offer(node.left);
                if (node.right != null) Q.offer(node.right);
            } else {
                if(!Q.isEmpty()) {
                    level++;
                    Q.offer(null);
                }
            }
        }
        return level;
    }
}