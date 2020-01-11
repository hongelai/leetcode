class Solution {
    boolean[][] visited;
    char[][] board;
    String word;
    int m, n;
    int[] xd = {0, 1, 0, -1};
    int[] yd = {1, 0, -1, 0};
    
    public boolean exist(char[][] board, String word) {
        if (board == null || board.length == 0 || board[0].length == 0) return false;
        
        int m = board.length, n = board[0].length;
        this.visited = new boolean[m][n];
        this.board = board;
        this.word = word;
        this.m = m;
        this.n = n;
        
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0)) return true;
            }
        return false;
    }
    
    private boolean dfs(int x, int y, int index) {
        boolean rs = false;
        

        if (board[x][y] == word.charAt(index)) {
            if (index+1 == word.length()) return true;
            
            visited[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int xc = x + xd[i];
                int yc = y + yd[i];

                if (xc >= 0 && xc < m
                        && yc >= 0 && yc < n
                        && !visited[xc][yc] && !rs) {
                    rs |= dfs(xc, yc, index+1);
                }
            }
            visited[x][y] = false;
        } else {
            return false;
        }
        
        return rs;
    }
}