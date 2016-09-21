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
    public class Pair {
        TreeNode node;
        int need;
        Pair(TreeNode x, int y) {
            node = x;
            need = y;
        }
    }
    
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        Stack<Pair> st = new Stack<Pair>();
        st.push(new Pair(root, sum));
        
        while (!st.isEmpty()) {
            Pair p = st.pop();
            TreeNode node = p.node;
            int need = p.need;
            
            if (node.left == null && node.right == null && node.val == need) return true;
            if (node.right != null) st.push(new Pair(node.right, need - node.val));
            if (node.left != null) st.push(new Pair(node.left, need - node.val));
            
        }
        return false;
    }
    
    public boolean hasPathSum1(TreeNode root, int sum) {
        if (root == null) return false;
        if (root.left == null && root.right == null && root.val == sum) return true;
        boolean left = false, right = false;
        if (root.left != null) left =  hasPathSum(root.left, sum - root.val);
        if (root.right != null) right = hasPathSum(root.right, sum - root.val);
        return left || right;
    }
}