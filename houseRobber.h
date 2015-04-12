    int rob(vector<int> &num) {
        int size = num.size();
        vector<int> dp(size+1, 0);
        for (int i = 0; i < size; i++) {
            dp[i+1] = max(dp[i], dp[i-1] + num[i]);
        }
        return dp[size];
    }