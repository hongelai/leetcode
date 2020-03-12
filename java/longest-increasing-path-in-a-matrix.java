class Solution {
    
    private int[][] cache;
    private int[][] direction = new int[][]{{0,1},{1,0},{0,-1},{-1,0}};
    
    //peeling onion
    //相当于topological sort的逆序，从最外层回溯到顶点，最长路径必定层数最多
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return 0;
        
        int m = matrix.length, n = matrix[0].length;
        int[][] outDegree = new int[m][n];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int[] d : direction) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x >= 0 && x < m
                        && y >= 0 && y < n 
                        && matrix[i][j] < matrix[x][y]) {
                        outDegree[i][j]++;
                    }
                }
            }
        }
        
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (outDegree[i][j] == 0) q.offer(new int[]{i,j});
            }
        }
        
        int height = 0;
        while (!q.isEmpty()) {
            height++;
            int size = q.size();
            
            for (int i = 0; i < size; i++) { 
                int[] node = q.poll();
                for (int[] d : direction) {
                    int x = node[0] + d[0];
                    int y = node[1] + d[1];
                    if (x >= 0 && x < m
                        && y >= 0 && y < n 
                        && matrix[node[0]][node[1]] > matrix[x][y]) {
                        --outDegree[x][y];
                        if (outDegree[x][y] == 0) q.offer(new int[]{x,y});
                    } 
                }
            }
        }
        
        return height;
    }
    
    public int longestIncreasingPath_dfs(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return 0;
        
        int m = matrix.length, n = matrix[0].length, max = Integer.MIN_VALUE;
        cache = new int[m][n];
        
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                max = Math.max(max, search(matrix, m, n, i, j));
            }
        }
        
        return max;
    }
    
    int search(int[][] matrix, int m, int n, int i, int j) {
        if (cache[i][j] != 0) return cache[i][j];
        
        for (int k = 0; k < 4; k++) {
            int ni = i + direction[k][0];
            int nj = j + direction[k][1];
            
            if (ni >= 0 && ni < m
               && nj >= 0 && nj < n
               && matrix[i][j] < matrix[ni][nj]) {
                cache[i][j] = Math.max(cache[i][j], search(matrix, m, n, ni, nj));
            }
        }
        
        return ++cache[i][j];
    }
}
