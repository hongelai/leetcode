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
    private int sum;
    public int sumNumbers(TreeNode root) {
        return dfs(root, 0);
    }
    
    private int dfs(TreeNode root, int sum) {
        if (root == null) return 0;
        sum = sum*10 + root.val;
        if (root.left == null && root.right == null) {
            return sum;
        }
        
        return dfs(root.left, sum) + dfs(root.right, sum);
    }
}