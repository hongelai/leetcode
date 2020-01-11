class Solution {
    public void solveSudoku(char[][] board) {
        if (board == null || board.length < 9 || board[0].length < 9) return;
        
        dfs(board, 0, 0);
    }
    
    private boolean dfs(char[][] board, int i, int j) {
        if (i == 9) return true;
        if (j >= 9) return dfs(board, i+1, 0); // move to next row
        
        if (board[i][j] == '.') {
            for (int k = 1; k <= 9; k++) {
                board[i][j] = (char)(k + '0');
                if(isValid(board, i, j)) {
                     if(dfs(board, i, j+1)) return true;
                }
                board[i][j] = '.';
            }
        }
        else {
            return dfs(board, i, j+1);
        }
        
        return false;
    }
    
    /*
     * Only need to compare (i, j) is equals to any other value
     * Do not need to persist existing values
     */
    private boolean isValid(char[][] board, int i, int j) {
        //compare row
        for (int r = 0; r < 9; r++) {
            if (r != i && board[r][j] == board[i][j]) return false;
        }
        
        //compare column
        for (int c = 0; c < 9; c++) {
            if (c != j && board[i][c] == board[i][j]) return false;
        }
        
        //compare cell
        int row = i/3*3, col = j/3*3;
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++) {
                if (r + row != i && c + col != j && board[r+row][c+col] == board[i][j]) return false;
            }
        
        return true;
    }
}