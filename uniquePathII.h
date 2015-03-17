    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        //f(m,n) = f(m,n-1) + f(m-1,n)
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m,vector<int>(n,-1));
        if(m == 0 && n == 0) return 0;
        
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for(int i = 1; i < m; i++) dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i-1][0]; //one way only, depend on previous as well
        for(int i = 1; i < n; i++) dp[0][i] = obstacleGrid[0][i] == 1 ? 0 : dp[0][i-1];
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++){
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        return dp[m-1][n-1];
    
    }

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        int dp[col] = {0};
        
        for (int i = 0; i < col && obstacleGrid[0][i] != 1; i++) dp[i] = 1;
        for (int i = 1; i < row; i++){
            if (obstacleGrid[i][0] == 1) dp[0] = 0;
            for(int j = 1; j < col; j++) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[col-1];
    }