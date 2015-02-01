    int minCut(string s) {
        int size = s.length();
        vector<vector<bool> > dp(size,vector<bool>(size));
        vector<int> f(size+1);
        //initialize with worst case, from i to size-1
        for(int i = 0; i <= size; i++) f[i] = size - 1 - i;
        
        for(int i = size-1; i >= 0; i--)
            for(int j = i; j < size; j++){
                if(s[i] == s[j] && (j-i < 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    f[i] = min(f[i],f[j+1] + 1);
                }        
            }
        return f[0];
    }