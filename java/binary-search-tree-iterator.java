/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class BSTIterator {
    List<TreeNode> list = new ArrayList<>();
    TreeNode cur;
    int index = 0;
    
    public BSTIterator(TreeNode root) {
        this.cur = root;
        Stack<TreeNode> st = new Stack<>();
        
        while (root != null || !st.isEmpty()) {
            if (root != null) {
                st.push(root);
                root = root.left;
            } else {
                TreeNode node = st.pop();
                list.add(node);
                if (node.right != null) {
                    root = node.right;
                }
            }
        }
    }
    
    /** @return the next smallest number */
    public int next() {
        return list.get(index++).val;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return index < list.size();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */