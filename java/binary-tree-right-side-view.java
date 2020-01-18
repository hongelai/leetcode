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
    public List<Integer> rightSideView(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> rs = new ArrayList<>();
        
        if (root == null) return rs;
        
        q.offer(root);
        
        while (!q.isEmpty()) {
            for (int i = q.size(); i > 0; i--) {
                TreeNode node = q.poll();
                
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
                if (i == 1) {
                    rs.add(node.val);
                }
            }
        }
        
        return rs;
    }
}