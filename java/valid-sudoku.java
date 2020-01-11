class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[][] row = new int[9][9];
        int[][] col = new int[9][9];
        int[][] cell = new int[9][9];
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0' - 1;
                    int cellIndex = i/3*3 + j/3;
                    
                    if (row[i][n] == 1 || col[j][n] == 1 || cell[cellIndex][n] == 1) return false;
                    row[i][n] = col[j][n] = cell[cellIndex][n] = 1;
                    
                }
            }
        }
        
        return true;
    }
}