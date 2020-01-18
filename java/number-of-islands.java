class Solution {
    public int numIslands(char[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return 0;
        
        int m = grid.length, n = grid[0].length, count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    color(grid, m, n, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    private void color(char[][] grid, int m, int n, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        
        if (grid[i][j] != '1') return;
        else grid[i][j] = '2';
        
        int[] di = {0, 1, 0, -1};
        int[] dj = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int x = i + di[k];
            int y = j + dj[k];
            color(grid, m, n, x, y);
        }
    }
}