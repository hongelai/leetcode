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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> rs = new ArrayList<List<Integer>>();
        LinkedList<TreeNode> q = new LinkedList<>();
        if (root != null) q.push(root);
        boolean leftToRight = true ;
        
        while (q.size() != 0) {
            LinkedList<Integer> row = new LinkedList<>();
            
            
            for (int i = q.size(); i > 0; i--) {
                TreeNode node = q.poll();
                if (leftToRight) {
                    row.addLast(node.val);
                }
                else {
                    row.addFirst(node.val);
                }
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
            
            leftToRight = !leftToRight;
            rs.add(row);
        }
        return rs;
    }
}