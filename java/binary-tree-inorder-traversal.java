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
    public List<Integer> inorderTraversal(TreeNode root) {
        return inorderTraversal_Iterative(root);
    }
    
    public void inorder(TreeNode root, List<Integer> res) {
        if (root != null) {
            inorder(root.left, res);
            res.add(root.val);
            inorder(root.right, res);
        }
    }
    
    public List<Integer> inorderTraversal_Iterative(TreeNode root) {
        Stack<TreeNode> stk = new Stack<>();
        List<Integer> rs = new ArrayList<>();
        TreeNode cur = root;
        
        while (cur != null || !stk.isEmpty()) {
            if (cur != null) {
                stk.push(cur);
                cur = cur.left;
            } else {
                cur = stk.pop();
                rs.add(cur.val);
                cur = cur.right;
            }
        }
        return rs;
    }
}