    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> entry;
        dfs(n,k,1,entry,res);
        return res;
    }
    void dfs(int n, int k, int index, vector<int> &entry, vector<vector<int> > &res){
        if(entry.size() == k){
            res.push_back(entry);
            return;
        } 
        
        for(int i = index; i < n+1; i++){
            entry.push_back(i);
            dfs(n,k,i+1,entry,res);
            entry.pop_back();
        }
    }