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
    HashMap<Integer, Integer> inorderMap = new HashMap<>(); 

    /*
     * Similar as preorder, but use the last node of a subtree in postorder sequence to split left&right from inorder seq
     * Time O(n), space O(logn)
     */
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        for (int i = 0; i < inorder.length; i++) {
            inorderMap.put(inorder[i], i);
        }
        
        return buildTree(inorder, postorder, 0, inorder.length-1, 0, postorder.length-1);
    }

    private TreeNode buildTree(int[] inorder, int[] postorder, int iStart, int iEnd, int pStart, int pEnd) {
        if (iStart > iEnd) return null;
        
        
        int i = inorderMap.get(postorder[pEnd]);
        int leftCount = i - iStart;

        TreeNode node = new TreeNode(inorder[i]);
        node.left = buildTree(inorder, postorder, iStart, i-1, pStart, pStart+leftCount-1);
        node.right = buildTree(inorder, postorder, i+1, iEnd, pStart+leftCount, pEnd-1);
        
        return node;
    }
}