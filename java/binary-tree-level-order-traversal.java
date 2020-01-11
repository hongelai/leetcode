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
    public List<List<Integer>> levelOrder(TreeNode root) {
        LinkedList<TreeNode> q = new LinkedList<>();
       List<List<Integer>> rs = new ArrayList<List<Integer>>();
        if (root != null) {
            q.offer(root);
        }
        
        while (!q.isEmpty()) {
            List<Integer> row = new ArrayList<>();
            
            for (int i = q.size(); i > 0; i--){
                TreeNode node = q.poll();
                row.add(node.val);
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
            rs.add(row);
        }
        return rs;
    }
}