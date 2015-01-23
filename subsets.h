    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> entry;
        res.push_back(entry);
        
        sort(S.begin(),S.end());
        dfs(S,0,entry,res);
        return res;
    }
    void dfs(vector<int> s,int index, vector<int> &entry, vector<vector<int> > &res){
        if(index >= s.size()) return;
        
        for(int i = index; i < s.size(); i++){
            entry.push_back(s[i]);
            res.push_back(entry);
            dfs(s,i+1,entry,res);
            entry.pop_back();
        }
    }