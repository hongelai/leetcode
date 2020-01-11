class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        boolean setFirstRow = false, setFirstCol = false;
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) setFirstRow = true;
                    if (j == 0) setFirstCol = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        
        if (setFirstRow) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (setFirstCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = matrix[i][0] = 0;
            }
        }
  
    }
}