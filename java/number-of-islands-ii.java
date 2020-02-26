class Solution {
    private static int m = 0, n = 0;
    
    public static class UF {
        int[] parent;
        int[] weight;
        int count = 0;
        
        UF() {
            parent = new int[m*n+1];
            weight = new int[m*n+1];
            
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    parent[i*n+j] = i*n+j;
                }
        }
        
        public int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        
        public boolean union(int x, int y) {
            int xr = find(x);
            int yr = find(y);
            
            if (xr == yr) return false;
            if (weight[xr] >= weight[yr]) {
                weight[xr] += weight[yr];
                parent[yr] = xr;
            } else {
                weight[yr] += weight[xr];
                parent[xr] = yr;
            }
            return true;
        }
        
    }
    
    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        this.m = m;
        this.n = n;
        ArrayList<Integer> res = new ArrayList<>();
        
        int[][] M = new int[m][n];
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        UF uf = new UF();
        
        for (int[] point : positions) {
            int x = point[0];
            int y = point[1];
            
            if (M[x][y] == 0) {
                M[x][y] = 1;
                uf.count++;
            }
            
            for (int k = 0; k < 4; k++) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                
                if (xx >= 0 && xx < m
                   && yy >= 0 && yy < n
                   && M[xx][yy] == 1) {
                    if (uf.union(x*n+y, xx*n+yy)) {
                        uf.count--;
                    }
                }
            }
            res.add(uf.count);
        }
        return res;
    }
}
