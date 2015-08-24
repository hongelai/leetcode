//dp[i][j] 是指S[0->i-1] 和 T[0->j-1] 之间匹配模式的个数
//无论S[i]和T[j]是否相等， 对于T[j](前j个字符)，至少有dp[i-1][j]中匹配模式
//若相等，还要加上dp[i-1][j-1]种的匹配模式 ，因为S[j]是新的，dp[i-1][j-1]里的
//每一种匹配模式加上S[j]都会有新组合，不会重复

    int numDistinct(string S, string T) {
        int M = S.length();
        int N = T.length();
        int dp[M+1][N+1];
        for(int i = 0; i <= M; i++) dp[i][0] = 1;
        for(int i = 1; i <= N; i++) dp[0][i] = 0;
        
        for(int i = 1; i <= M; i++)
            for(int j = 1; j <= N; j++)
            {
                dp[i][j] = dp[i-1][j] + (S[i-1] == T[j-1] ? dp[i-1][j-1] : 0); //为什么不考虑dp[i][j-1]? 因为 dp[i][j]一定要包括T[j-1]在内
            }
        return dp[M][N];
    }
    //rolling array
    int numDistinct(string S, string T) {
        int M = S.length();
        int N = T.length();
        int dp[N+1];
        dp[0] = 1;
        for(int i = 1; i <= N; i++) dp[i] = 0;
        int upper_left = dp[0];
        
        for(int i = 1; i <= M; i++){
            upper_left = dp[0];
            for(int j = 1; j <= N; j++)
            {
                int tmp = dp[j];
                dp[j] = dp[j] + (S[i-1] == T[j-1] ? upper_left : 0);
                upper_left = tmp;
            }
            
        }
        return dp[N];
    }