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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(root == null) return result;
        Queue<TreeNode> q = new LinkedList();
        q.offer(root);
        q.offer(null);
        result.add(new ArrayList<Integer>());
        int level = 0;
        
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node != null) {
                result.get(level).add(node.val);
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
                
            } else {
                if (!q.isEmpty()) {
                    result.add(new ArrayList<Integer>());
                    level++;
                    q.offer(null);
                }
            }
        }
        return result;
    }
    
    public List<List<Integer>> levelOrder1(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (root == null) return result;
        orderTraverse(root, 0, result);
        return result;
    }
    
    public void orderTraverse(TreeNode root, int level, List<List<Integer>> result) {
        if (root == null) return;
        if (result.size() <= level) result.add(new ArrayList<Integer>());
        result.get(level).add(root.val);
        orderTraverse(root.left, level+1, result);
        orderTraverse(root.right, level+1, result);
    }
    
    
    
 }