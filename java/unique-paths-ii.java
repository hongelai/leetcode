class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        int[] dp = new int[n];
        
        dp[n-1] = obstacleGrid[m-1][n-1] == 1 ? 0 : 1;
        for (int i = n-2; i >= 0; i--) {
            if (obstacleGrid[m-1][i] == 1) dp[i] = 0;
            else dp[i] = dp[i+1];
        }
        
        for (int i = m-2; i >= 0; i--) {
            if (obstacleGrid[i][n-1] == 1) dp[n-1] = 0;
            for (int j = n - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else {
                    dp[j] = dp[j+1] + dp[j];
                }
            }
        }
        
        return dp[0];
    }
}