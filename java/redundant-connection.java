class Solution {
    private static int MAX_VERTICE = 1001;
    
    public static class UF {
        int[] parent = new int[MAX_VERTICE];
        int[] weight = new int[MAX_VERTICE];
        
        UF() {
            for (int i = 0; i < MAX_VERTICE; i++) parent[i] = i;
            Arrays.fill(weight, 1);
        }
        
        /* Close to O(1) 因为不断把节点放到根节点下，树高 ～= 2
        */
        public int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]); //溯源到根，并更新为根节点，降低了树的高度
            return parent[x];
        }
        
        /*把小树并到大树可以降低树的高度 Close to O(1)
        */
        public boolean union(int x, int y) {
            int xr = find(x);
            int yr = find(y);
            
            if (xr == yr) return false;
            else if (weight[xr] >= weight[yr]) {
                parent[yr] = xr;
                weight[yr] += weight[xr];
            }
            else {
                parent[xr] = yr;
                weight[xr] += weight[yr];
            }
            return true;
        }
    }
    
    public int[] findRedundantConnection_1(int[][] edges) {
        UF set = new UF();
        
        for (int[] edge : edges) {
            if (!set.union(edge[0], edge[1])) return edge;
        }
        return new int[]{-1, -1};
    }
    
    public int[] findRedundantConnection(int[][] edges) {
        ArrayList<Integer>[] graph = new ArrayList[MAX_VERTICE];
        HashSet<Integer> seen = new HashSet<>();
        
        for (int i = 0; i < MAX_VERTICE; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        
        //不初始化graph，边dfs边添加edge， 一旦形成cycle，则说明这条edge多余
        for (int[] edge : edges) {
            int source = edge[0];
            int target = edge[1];
            seen.clear();
            
            if (!graph[source].isEmpty() 
                && findCycle(graph, seen, source, target)) {
                return edge;
            }
       
            graph[source].add(target);
            graph[target].add(source);
        }
        
        return new int[]{-1,-1};
    }
    
    private boolean findCycle(ArrayList<Integer>[] graph, HashSet<Integer> seen, int source, int target) {
        if (!seen.contains(source)) {
            if (source == target) return true;
        
            seen.add(source);
            for (int next : graph[source]) {
                if (findCycle(graph, seen, next, target)) return true;
            }
        }
        
        return false;
    }
}
