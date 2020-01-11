/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    HashMap<Node, Node> map = new HashMap<Node, Node>();
    
    // DFS : 每层递归clone 一个节点，neighbors由下层递归返回
    public Node cloneGraph(Node node) {
        Node newNode = map.get(node);
        if(newNode != null) {
            return newNode;
        } else {
            newNode = new Node(node.val, new ArrayList<Node>());
            map.put(node, newNode);
        }
        
        for(Node n : node.neighbors) {
            newNode.neighbors.add(cloneGraph(n));
        }
        
        return newNode;
    }
    
    // BFS : 用map来映射新老节点，map里面的节点都是访问过的节点
    // 在队列里面的节点都是需要填充neighbor的节点
    public Node cloneGraph_1(Node node) {
        if (node == null) return null;
        
        
        LinkedList<Node> q = new LinkedList<>();
        
        q.offer(node);
        map.put(node, new Node(node.val, new ArrayList<Node>()));
        
        while (!q.isEmpty()) 
        {
            Node cur = q.poll();
            List<Node> newNeighbors = map.get(cur).neighbors;
            
            for (Node neighbor: cur.neighbors) 
            {
                Node newNode = map.get(neighbor);
                
                if (newNode == null) {
                    newNode = new Node(neighbor.val, new ArrayList<Node>());
                    q.add(neighbor);
                    map.put(neighbor, newNode);
                }
                
                newNeighbors.add(newNode);
            }
        }
        
        return map.get(node);
    }
}