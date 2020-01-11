class Solution {
    public List<Integer> spiralOrder_1(int[][] matrix) {
        List<Integer> rs = new ArrayList<>();
        if (matrix == null || matrix.length == 0) return rs;
        
        int m = matrix.length, n = matrix[0].length;
        int i = 0, j = 0, minRow = 0, maxRow = m-1, minCol = 0, maxCol = n-1;
        
        while (minRow <= maxRow  && minCol <= maxCol) {
            for (j = minCol; j <= maxCol; j++) {
                rs.add(matrix[minRow][j]);
            }
            if(++minRow > maxRow) break;
            
            for (i = minRow; i <= maxRow; i++) {
                rs.add(matrix[i][maxCol]);
            }
            if (minCol > --maxCol) break;
            
            for (j = maxCol; j >= minCol; j--) {
                rs.add(matrix[maxRow][j]);
            }
            if (minRow > --maxRow) break;
            
            for (i = maxRow; i >= minRow; i--) {
                rs.add(matrix[i][minCol]);
            }
            if (++minCol > maxCol) break;
        }
        return rs;
    }
    
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> rs = new ArrayList<>();
        if (matrix == null || matrix.length == 0) return rs;
        
        int m = matrix.length, n = matrix[0].length;
        int[] dr = {0, 1, 0, -1};
        int[] dc = {1, 0, -1, 0};
        int di = 0; // delta index
        int r = 0, c = 0;
        boolean[][] seen = new boolean[m][n];
        
        for (int i = 0; i < m*n; i++) {
            rs.add(matrix[r][c]);
            seen[r][c] = true;
            
            int nr = r + dr[di];
            int nc = c + dc[di];
            //caculate next cooridinator
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !seen[nr][nc]) {
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