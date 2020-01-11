class Solution {
    //扫面矩阵的四条边，从任何‘O’开始dfs， 够不到的就是封闭区间
    public void solve(char[][] board) {
        if (board.length == 0 || board[0].length == 0) return;
        int m = board.length, n = board[0].length;
        
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && 
                    (i == 0 || i == m-1 || j == 0 || j == n-1)) {
                    dfs(board, m, n, i, j);
                }
            }
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'V') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
    }
    
    private void dfs(char[][] board, int m, int n, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (board[i][j] == 'X' || board[i][j] == 'V') return;
        
        int[] dj = {1, 0, -1, 0};
        int[] di = {0, 1, 0, -1};
        board[i][j] = 'V';
        
        for (int k = 0; k < 4; k++) {
            int x = i + di[k];
            int y = j + dj[k];
            dfs(board, m, n, x, y);
        }
    }
}