/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        if (root == null) return null;
        if (root.left != null) root.left.next = root.right;
        if (root.right != null) root.right.next = root.next != null ? root.next.left : null;
        connect(root.left);
        connect(root.right);
        
        return root;
    }
    
    public Node connect_1(Node root) {
        LinkedList<Node> q = new LinkedList<>();
        
        if (root != null) q.add(root);
        
        while (q.size() > 0) {
            
            for (int i = q.size(); i > 0; i--) {
                Node node = q.poll();
                if (i > 1) { //not the last node of that level
                    node.next = q.peek();
                } else {
                    node.next = null;
                }
                
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
        }
        
        return root;
    }
}