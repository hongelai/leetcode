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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder, inorder, 0, inorder.length-1, 0);
    }
    
    private TreeNode buildTree(int[] preorder, int[] inorder, int iStart, int iEnd, int pIndex) {
        if (iStart > iEnd) return null;
        TreeNode node = null;
        for (int i = iStart; i <= iEnd; i++) {
            if (preorder[pIndex] == inorder[i]) {
                node = new TreeNode(inorder[i]);
                int leftSideCount = i - iStart;
                
                node.left = buildTree(preorder, inorder, iStart, i-1, pIndex+1);
                node.right = buildTree(preorder, inorder, i+1, iEnd, pIndex+leftSideCount+1);
                break;
            }
        }
        return node;
    }
}