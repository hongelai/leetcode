public class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[] used = new boolean[9];
        
        
        for (int i = 0; i < 9; i++) {
            Arrays.fill(used, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    if(used[board[i][j] - '1']) return false;
                    else used[board[i][j] - '1'] = true;
            }
            
            Arrays.fill(used, false);
            for (int k = 0; k < 9; k++) {
                if (board[k][i] != '.')
                    if(used[board[k][i] - '1']) return false;
                    else used[board[k][i] - '1'] = true;
            }
            
            Arrays.fill(used, false);
            for (int m = 0; m < 9; m++){
                int col = i/3*3 + m/3;
                int row = i%3*3 + m%3;
                if (board[row][col] != '.')
                    if(used[board[row][col] - '1']) return false;
                    else used[board[row][col] - '1'] = true; 
            }
        }
        return true;
    }
}