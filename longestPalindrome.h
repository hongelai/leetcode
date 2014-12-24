    string longestPalindrome(string s) {
        int length = s.length();
        // vector<vector<bool> > dp(length,vector<bool>(length)); // time limit exceeded
        bool dp[1000][1000] = {false};
        string res= "";
        int max = 0;
        int start = 0, end = length -1;
        
        for(int i = length - 1 ; i >= 0; i--)
            for(int j = i; j < length; j++){
                dp[i][j] = (s[i]==s[j]) && (i+2 > j || dp[i+1][j-1]);
                if(dp[i][j] && j - i >= max){
                    max = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        return s.substr(start,end-start+1);
    }