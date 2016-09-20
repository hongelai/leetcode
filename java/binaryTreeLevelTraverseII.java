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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (root == null) return result;
        result.add(new ArrayList<Integer>());
        Queue<TreeNode> Q = new LinkedList<TreeNode>();
        int level = 0;
        Q.offer(root);
        Q.offer(null);
        
        while (!Q.isEmpty()) {
            TreeNode node = Q.poll();
            if (node != null) {
                result.get(level).add(node.val);
                if (node.left != null) Q.offer(node.left);
                if (node.right != null) Q.offer(node.right);
            } else {
                if (!Q.isEmpty()) {
                    level ++;
                    Q.offer(null);
                    result.add(new ArrayList<Integer>());
                }
            }
        }
        Collections.reverse(result);
        return result;
    }
}