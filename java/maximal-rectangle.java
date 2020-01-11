class Solution {
    char[][] matrix;
    //brute force O(N2M2)
    public int maximalRectangle(char[][] matrix) {
        this.matrix = matrix;
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        
        int m = matrix.length, n = matrix[0].length, rs = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] - '0' == 1) {
                    rs = Math.max(rs, findMaxArea(i, j, m-1, n-1));
                }
            }
        }
        return rs;
    }
    
    public int findMaxArea(int r, int c, int row, int col) {
        int rs = 0;
        for (int i = r; i  <= row; i++) {
            int j = c;
            for (; j <= col; j++) {
                if (matrix[i][j] - '0' == 0) {
                    col = j - 1;
                } else {
                    int area = (i - r+1) * (j - c+1);
                    rs = Math.max(rs, area);
                }
            }
        }
        return rs;
    }

    //O(MN)
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
        
        int M = matrix.length, N = matrix[0].length;
        int[] height = new int[N+1];
        int rs = 0;
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] - '0' == 0) {
                    height[j] = 0;
                } else {
                    height[j]++;
                }
            }
            rs = Math.max(rs, getLargestRectangle(height));
        }
        return rs;
    }
    
    private int getLargestRectangle(int [] height) {
        Stack<Integer> st = new Stack<>();
        int rs = 0;
        
        for (int i = 0; i < height.length;) {
            if (st.isEmpty() || height[i] > height[st.peek()]) {
                st.push(i++);
            } else {
                int top = st.pop();
                int dist = st.isEmpty() ? i : i - st.peek() - 1;
                rs = Math.max(rs, height[top] * dist);
            }
        }
        return rs;
    }
}