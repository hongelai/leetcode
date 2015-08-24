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


    //dp solution
    //idea: for each substr 0....i, create a solution entry
    //      for each solution, generate substring j...i, check if sub(j,i) is in dict
    //      if it is in dict, add sub to solution map(j-1) to genereate solution map[i];
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length(), size = dict.size();
        vector<string> ret;
        unordered_map<int, vector<string> > map;
        
        
        if (!isPossible(s,dict)) return ret;
        ret.push_back("");
        map[0] = ret;
        for (int i = 0; i < len; i++) {
            vector<string> entry;
            map[i+1] = entry;
            for (int j = 0; j <= i; j++) { //0,....j,j+1,....i
                string sub = s.substr(j, i-j+1);
                if (dict.count(sub) != 0) {
                    for (const auto& str : map[j]) {

                        map[i+1].push_back(str+(str.empty() ? "" : " ") + sub);
                    }
                }
            }
        }
        return map[len];
    }
    bool isPossible(string s, unordered_set<string> &dict) { 
        int len = s.length();
        bool dp[len+1] = {false};
        dp[0] = true;
        
        for (int i = 0; i < len; i++) {
            if (dp[i]) {
                for (int j = i; j < len; j++){
                    if (dict.count(s.substr(i,j-i+1)) != 0){
                        dp[j+1] = true;
                    }
                }
            }    
        }
        return dp[len];
    }