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
    int max;
    public int maxPathSum(TreeNode root) {
        if (root == null) return 0;
        max = Integer.MIN_VALUE;
        helper(root);
        return max;
    }
    
    // @return : max sum from current node to either left or right
    public int helper(TreeNode root) {
        if (root == null) return 0;
        
        int left = Math.max(0, helper(root.left));
        int right = Math.max(0, helper(root.right));
        
        max = Math.max(max, left + right + root.val);
        
        return Math.max(left, right) + root.val;
    }
    
    public int maxPathSum_1(TreeNode root) {
        HashMap<TreeNode, Integer> map = new HashMap<>();
        if (root == null) return 0;
        
        calculateMaxChild(root, map);
        return calculateMaxPath(root, map);
    }
    
    // max path that with current node as root
    public int calculateMaxPath(TreeNode root, HashMap<TreeNode, Integer> map) {
        if (root == null) return 0;
        
        int sum = root.val, left = Integer.MIN_VALUE, right = Integer.MIN_VALUE;
        if (root.left != null) {
            left = calculateMaxPath(root.left, map);
            sum += map.get(root.left) > 0 ? map.get(root.left) : 0;
        }
        if (root.right != null) {
            right = calculateMaxPath(root.right, map);
            sum += map.get(root.right) > 0 ? map.get(root.right) : 0;
        }
        
        return Math.max(sum, Math.max(left, right));
    }
    
    // max sum from current node to either left or right
    public int calculateMaxChild(TreeNode root, HashMap<TreeNode, Integer> map) {
        if (root == null) return 0;
        int left = 0, right = 0;
        if (root.left != null) left = calculateMaxChild(root.left, map);
        if (root.right != null) right = calculateMaxChild(root.right, map);
        
        int val = Math.max(0, Math.max(left, right)) + root.val;
        map.put(root, val);
        return val;
    }
}