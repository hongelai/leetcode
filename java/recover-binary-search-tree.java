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
    TreeNode first = null, second = null, prev = null;
    
    // Morris traversal
    public void recoverTree(TreeNode root) {
        TreeNode cur = root, pre = null;
        
        while (cur != null) {
            if (cur.left == null) { //leftmost
                if (pre != null && pre.val >= cur.val) {
                    if (first == null) {
                        first = pre;
                    }
                    second = cur;
                }
                pre = cur;
                
                cur = cur.right;
            }
            else {
                TreeNode p = cur.left; //p is the temp pointer to find the rightmost node
                while (p.right != null && p.right != cur) {
                    p = p.right;
                }
                
                if (p.right == null) { // not connect
                    p.right = cur;
                    cur = cur.left;
                }
                else { 
                    if (pre != null && pre.val >= cur.val) {
                        if (first == null) {
                            first = pre;
                        }
                        second = cur;
                    }
                    pre = cur;
                    
                    p.right = null;
                    cur = cur.right;
                }
            }
        }
        if (first != null) {
            int tmp = first.val;
            first.val = second.val;
            second.val = tmp;
        }
    }
    
    public void recoverTree_2(TreeNode root) {
        if (root == null) return;
        
        inorder(root);
        
        if (first != null) {
            int tmp = first.val;
            first.val = second.val;
            second.val = tmp;
        }
    }
    
    private void inorder(TreeNode cur) {
        if (cur == null) return;
        
        inorder(cur.left);
        
        if (prev != null && prev.val >= cur.val) {
            if (first == null) {
                first = prev;
            }
            second = cur;
        }
        prev = cur;
        
        inorder(cur.right);
    }
    
    public void recoverTree_1(TreeNode root) {
        List<TreeNode> nodes = new ArrayList<>();
        inorder(root, nodes);
        // 4 2 3 1 5  6
        TreeNode first = null, second = null;
        for (int i = 1; i < nodes.size(); i++) {
            if (nodes.get(i).val < nodes.get(i-1).val) {
                if (first == null) first = nodes.get(i-1);
                second = nodes.get(i);
            }
        }
        int tmp = first.val;
        first.val = second.val;
        second.val = tmp;
    }
    
    private void inorder(TreeNode root, List<TreeNode> nodes) {
        if (root == null) return;
        inorder(root.left, nodes);
        nodes.add(root);
        inorder(root.right, nodes);
    }
}