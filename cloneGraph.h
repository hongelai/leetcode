class Solution {
    //use map to keep track of visited node
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        if(visited.find(node->label) != visited.end()) return visited[node->label];
        
        UndirectedGraphNode* gNode = new UndirectedGraphNode(node->label);
        visited[node->label] = gNode;
        
        vector<UndirectedGraphNode *> neighbors;
        for(int i = 0; i < node->neighbors.size(); i++){
            auto nb = cloneGraph(node->neighbors[i]);
            gNode->neighbors.push_back(nb);
            visited[nb->label] = nb;
        }
        return gNode;
    }
private: 
    unordered_map<int,UndirectedGraphNode*> visited;
};