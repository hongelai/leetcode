    bool wordBreak(string s, unordered_set<string> &dict) {
        int size = s.size();
        vector<bool> dp(size+1,false);
        dp[0] = true;
        
        for(int i = 0; i < size; i++){
            if(dp[i]){
                for(int  j = i; j < size; j++){
                   string sub = s.substr(i,j - i + 1);
            
                   if(dict.find(sub) != dict.end()){
                       dp[j+1] = true;
                   } 
                }
            }
        }
        
        return dp[size];
    }