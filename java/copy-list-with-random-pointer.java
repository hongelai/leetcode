/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    // insert new node after old node, then split after copying
    public Node copyRandomList(Node head) {
        if (head == null) return null;
        
        Node cur = head;
        
        //create shadow node 
        while (cur != null) {
            Node node = new Node(cur.val);
            node.next = cur.next;
            cur.next = node;
            
            cur = cur.next.next;
        }
        
        // copy random pointer
        cur = head;
        while (cur != null) {
            Node newNode = cur.next;
            if (cur.random != null) newNode.random = cur.random.next;
            
            cur = cur.next.next;
        }
        
        // split two list
        Node rs = head.next;
        cur = head;
        while (cur != null) {
            Node t = cur.next;
            cur.next = t.next;
            if (cur.next != null) t.next = cur.next.next;
            
            cur = cur.next;
        }
        
        return rs;
    }
    
    //use hashmap to maintain mappping
    public Node copyRandomList_1(Node head) {
        HashMap<Node, Node> map = new HashMap<>();
        
        Node cur = head;
        while (cur != null) {
            Node newNode = new Node(cur.val);
            map.put(cur, newNode);
            cur = cur.next;
        }
        
        cur = head;
        while (cur != null) {
            Node newNode = map.get(cur);
            newNode.next = map.get(cur.next);
            newNode.random = map.get(cur.random);
            cur = cur.next;
        }
        
        return map.get(head);
    }
}