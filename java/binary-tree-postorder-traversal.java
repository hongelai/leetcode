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
    public List<Integer> postorderTraversal(TreeNode root) {
        return postOrder_iterative(root);
    }
    
    public List<Integer> postOrder_iterative(TreeNode root) {
        List<Integer> rs = new ArrayList<>();
        Stack<TreeNode> stk = new Stack<>();
        TreeNode cur = root;
        TreeNode lastVisited = null;
        
        while (cur != null || !stk.isEmpty()) {
            if (cur != null) {
                stk.push(cur);
                cur = cur.left;
            }
            else {
                TreeNode node = stk.peek(); // cannot pop because it may have right leaf
                if (node.right != null && node.right != lastVisited) {
                    cur = node.right;
                }
                else {
                    rs.add(node.val);
                    lastVisited = stk.pop();
                }
            }
        }
        return rs;
    }
    
    public void postOrder(TreeNode root, List<Integer> rs) {
        if (root == null) return;
        postOrder(root.left, rs);
        postOrder(root.right, rs);
        rs.add(root.val);
    }
}