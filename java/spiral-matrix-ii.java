class Solution {
    public int[][] generateMatrix(int n) {
        int[][] rs = new int[n][n];
        boolean[][] seen = new boolean[n][n];
        int[] dr = {0, 1, 0, -1};
        int[] dc = {1, 0, -1, 0};
        int di = 0, r = 0, c = 0;
        
        for (int i = 1; i <= n*n; i++) {
            rs[r][c] = i;
            seen[r][c] = true;
            int nr = r + dr[di];
            int nc = c + dc[di];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !seen[nr][nc]) {
                r = nr;
                c = nc;
            } else {
                di = (di + 1) % 4;
                r = r + dr[di];
                c = c + dc[di];
            }
        }
        return rs;
    }
}