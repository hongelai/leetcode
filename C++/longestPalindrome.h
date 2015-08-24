    string longestPalindrome(string s) {
        int len = s.length();
        string res = "";
        bool dp[len][len] = {false};
        
        for(int i = len-1; i >= 0; i--)
            for(int j = i; j < len; j++){
                dp[i][j] = s[i] == s[j] && (j-i < 2 || dp[i+1][j-1]);
                if(dp[i][j] && j - i + 1 > res.length()){
                    res = s.substr(i,j-i+1);
                }
            }
        return res;
    }