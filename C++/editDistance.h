    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1)); //dp[i][j] means the min distance changing word1.substr(1->i) to word2.substr(1->j)
        for (int i = 0; i <= len1; i++) dp[i][0] = i; //word2 is empty, delete word1 char by char
        for (int i = 0; i <= len2; i++) dp[0][i] = i;
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++){
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;//replace, delete, add
                }
            }
        }
        return dp[len1][len2];
    }
    /*
    if word1[i] = word2[j], then same
    else
        word1 = dp[i] = str+c, then dp[i-1] = str,
        word2 = dp[j] = str+d, then dp[j-1] = str
        replace d with c, dp[i-1][j-1] + 1
        delete c, dp[i][j-1] + 1, strc - c --> str == dp[j-1]
        add d, dp[i-1][j] + 1, str + d + (c) --> strd == dp[j]
    */