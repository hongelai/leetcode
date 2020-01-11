class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return false;
        
        int m = matrix.length, n = matrix[0].length;
        
        int low = 0, high = m-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (high < 0) return false;
        
        int row = high;
        low = 0; high = n-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
}