class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        //对角线复制 然后左右复制
        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++) {
                swap(matrix, i, j, j, i);
            }
        
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n/2; j++) {
                swap(matrix, i, j, i, n - j - 1);
            }
        
    }
    
    private void swap(int[][] matrix, int i, int j, int x, int y) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[x][y];
        matrix[x][y] = tmp;
    }
}