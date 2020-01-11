class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length(), n = t.length();
        int[][] dp = new int[n+1][m+1];
        
        for (int i = 0; i <= m; i++) dp[0][i] = 1;
            
        for (int i = 1; i <= n; i++) 
            for (int j = i; j <= m; j++) {
                // dp[i][j]一定要包括T[i-1]在内
                dp[i][j] = dp[i][j-1] + (s.charAt(j-1) == t.charAt(i-1) ? dp[i-1][j-1] : 0);
            }
        return dp[n][m];
    }
}