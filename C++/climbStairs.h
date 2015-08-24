int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 0, dp[1] = 1, dp[2] = 2;
        for (int i  = 3; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];//最后一下可能走一步或者两步
        
        return dp[n];
    }