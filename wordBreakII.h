    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        int size = s.size();
        if(!isPossible(s,dict,size)) return res;
        
        dfs(0,size,"",s,dict,res);
        
        return res;
        
    }
    void dfs(int index, int size, string entry, string &s, unordered_set<string> &dict, vector<string> &res){
        if(index == size){
            entry.pop_back();
            res.push_back(entry);
        }
        
        for(int i = index; i < size; i++){
            string sub = s.substr(index, i - index + 1);
            if(dict.find(sub) != dict.end()){
                dfs(i+1,size,entry + sub + " ",s,dict,res);
            }
            
        }
    }
    bool isPossible(string s, unordered_set<string> &dict, int size){
        vector<bool> dp(size+1,false);
        dp[0] = true;
        
        for(int i = 0; i < size; i++){
            if(dp[i]){
                for(int  j = i; j < size; j++){
                   string sub = s.substr(i,j - i + 1);
                   if(dict.find(sub) != dict.end()) dp[j+1] = true; 
                }
            }
        }
        return dp[size];
    }

    //complexity O(n!)
    //T(n)  = n * (T(n-1) + O(1))