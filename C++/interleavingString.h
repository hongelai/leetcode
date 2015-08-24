    bool isInterleave(string s1, string s2, string s3) {
        //first solution: recursion, (s1[0] == s3[0] && recurse(s1+1, s2, s3+1)) || (s1[0] == s3[0] &&recurse(s1, s2+1, s3+1))
        //second solution: dp[i+1][j+1] means s3[0->i+j] is interleaving string of s1[0->i] and s2[0->j]
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        int dp[len1+1][len2+1] = {false};
        if (len1+len2 != len3) return false;
        
        dp[0][0] = true;
        for (int i = 1; i <= len1; i++) dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        for (int j = 1; j <= len2; j++) dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return dp[len1][len2];
    }