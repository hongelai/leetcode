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
    public void flatten(TreeNode root) {
        flatten(root, null);
    }
    /**
    
        1
       / \
      2   5
     / \   \
    3   4   6
    -----------        
    pre = 5
    cur = 4

        1
       / 
      2   
     / \   
    3   4
         \
          5
           \
            6
    -----------        
    pre = 4
    cur = 3

        1
       / 
      2   
     /   
    3 
     \
      4
       \
        5
         \
          6
    -----------        
    cur = 2
    pre = 3

        1
       / 
      2   
       \
        3 
         \
          4
           \
            5
             \
              6
    -----------        
    cur = 1
    pre = 2

    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
              
    **/
    private TreeNode flatten(TreeNode cur, TreeNode pre) {
        if (cur == null) return pre;
        pre = flatten(cur.right, pre);
        pre = flatten(cur.left, pre);
        
        cur.right = pre;
        cur.left = null;
        pre = cur;
        return pre;
    }
    
    public void flatten_1(TreeNode root) {
        if (root == null) return;
        //Tree is constructed in preorder, so all nodes in left tree
        //are visited before right tree
        if (root.left != null) flatten(root.left);
        if (root.right != null) flatten(root.right);
        
        TreeNode tmp = root.right;
        root.right = root.left;
        root.left = null;
        while(root.right != null) root = root.right;
        root.right = tmp;
        
    }
  
}