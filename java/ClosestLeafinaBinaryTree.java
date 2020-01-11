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
    Map<TreeNode, LeafResult> distMap = new HashMap<>();
    List<TreeNode> path = new ArrayList<>();

    public int findClosestLeaf(TreeNode root, int k) {
        dfs(root);
        buildPath(root, k);

        int res = Integer.MAX_VALUE;
        TreeNode target = new TreeNode(-1);
        for (int i = 0; i < path.size(); i++) {
            TreeNode node = path.get(i);
            int len = distMap.get(node).dist + path.size() - 1 - i;
            if (len < res) {
                res = len;
                target = distMap.get(node).leaf;
            }
        }
        return target.val;
    }

    public boolean buildPath(TreeNode root, int k) {
        if (root == null) return false;

        path.add(root);
        if (root.val ==  k){
            return true;
        }

        boolean left = buildPath(root.left, k);
        if (!left) {
            boolean right =  buildPath(root.right, k);
            if (!right) {
                path.remove(path.size() - 1);
                return false;
            }
        }
        return true;
    }

    public LeafResult dfs(TreeNode root) {
        if (root == null) return new LeafResult(Integer.MAX_VALUE, null);
        if (root.left == null && root.right == null) {
            distMap.put(root, new LeafResult(0, root));
            return new LeafResult(0, root);
        }

        LeafResult left = dfs(root.left);
        LeafResult right = dfs(root.right);
        if (left.dist <= right.dist) {
            distMap.put(root, new LeafResult(left.dist + 1, left.leaf));
        } else {
            distMap.put(root, new LeafResult(right.dist + 1, right.leaf));
        }
        return distMap.get(root);
    }

    public class LeafResult {
            int dist;
            TreeNode leaf;

            LeafResult(int dist, TreeNode leaf) {
                this.dist = dist;
                this.leaf = leaf;
            }
    }
    
    
}