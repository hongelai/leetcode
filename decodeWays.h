//f(n) = f(n-1) + f(n-2). To get to f(n), either f(n-1) + 1 or f(n-2) + 1 with precondition that they are valid
//similar as climbing stairs
    int numDecodings(string s) {
        int len = s.length();
        if(len < 1 || s[0] == '0') return 0;  
        vector<int> dp(len+1);
        dp[0] = dp[1] = 1;
        
        for(int i = 1; i < len; i++){ // "11" = 2 , dp[0] has no meaning
            if(s[i] == '0'){
                if(s[i-1] != '1' && s[i-1] != '2') return 0;
                dp[i+1] = dp[i-1];
            } 
            else{
                int num = s[i] - '0' + (s[i-1] - '0')*10;
                if(num <= 26 && num > 10) dp[i+1] = dp[i-1] + dp[i];
                else dp[i+1] = dp[i];
            }
        }
        return dp[len];
    } 