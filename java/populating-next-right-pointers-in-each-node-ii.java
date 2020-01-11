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
        //use a dummy node to solve the pre
        if (root == null) return null;
        
        Node dummy = new Node(-1);
        for (Node cur = root, pre = dummy; cur != null; cur = cur.next) {
            if (cur.left != null) {
                pre.next = cur.left;
                pre = pre.next;
            }
            if (cur.right != null) {
                pre.next = cur.right;
                pre = pre.next;
            }
        }
        connect(dummy.next);
        
        return root;
    }
    
    public Node connect_4(Node root) {
        if (root == null) return null;
        
        Node first = null;
        for (Node cur = root, pre = null; cur != null; cur = cur.next) {
            if (first == null) {
                first = cur.left != null ? cur.left : cur.right;
            }
            if (cur.left != null) {
                if (pre != null) pre.next = cur.left;
                pre = cur.left;
            }
            if (cur.right != null) {
                if (pre != null) pre.next = cur.right;
                pre = cur.right;
            }
        }
        connect(first);
        
        return root;
    }
    
    public Node connect_3(Node root) {
        Node cur = root;
        
        while (cur != null) { //loop tree
            Node pre = null; // previous node of next level
            Node first = null; // first node of next level
            
            while (cur != null) { //loop level
                if (first == null) {
                    first = cur.left != null ? cur.left : cur.right;
                }
                if (cur.left != null) {
                    if (pre != null) pre.next = cur.left;
                    pre = cur.left;
                }
                if (cur.right != null) {
                    if (pre != null) pre.next = cur.right;
                    pre = cur.right;
                }
                cur = cur.next;
            }
            
            cur = first;
        }
        
        return root;
    }
    
    public Node connect_2(Node root) {
        if (root == null) return null;
        
        //scan first sibling that does not belong to same parent
        Node p = root.next;
        while(p != null) {
            if (p.left != null) {
                p = p.left; //use the same pointer to store the result
                break;
            }
            if (p.right != null) {
                p = p.right;
                break;
            }
            p = p.next;
        }
        
        if (root.left != null) {
            root.left.next = root.right == null ? p : root.right;
        }
        if (root.right != null) root.right.next = p;
        
        connect(root.right); // connect right first, so that nodes in left side can iterate all the way to the right by node.next
        connect(root.left);
        
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