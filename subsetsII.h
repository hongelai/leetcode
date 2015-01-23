    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res(1);//initialize size to 1, then can push case [] at the beginning;
        vector<int> entry;
        int size = S.size();
        sort(S.begin(),S.end());
        for(int i = 0; i < size; i++){ //[]; 1; 2; 1,2; 3; 1,3; 2,3; 1,2,3; ...
            
            int sz = res.size();
            for(int j = 0; j < sz; j++){
                
                    entry = res[j];
                    entry.push_back(S[i]);
                    res.push_back(entry);
            }
        }
        //remove duplicate
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
    //de-duplicate on the fly
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res(1);//initialize size to 1, then can push case [] at the beginning;
        vector<int> entry;
        int size = S.size();
        int preIndex = 0;
        
        sort(S.begin(),S.end());
        for(int i = 0; i < size; i++){ //[]; 1; 2; 1,2; 2,2; 1,2,2; ...
            
            int sz = res.size();
            for(int j = 0; j < sz; j++){
                if(i== 0 || S[i] != S[i-1] || j >= preIndex){ //when dup happens,start from the index of the last same element
                    entry = res[j];
                    entry.push_back(S[i]);
                    res.push_back(entry);
                }
            }
            preIndex = sz;
        }
        
        return res;
    }

    //recursvive
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res(1);//initialize size to 1, then can push case [] at the beginning;
        vector<int> entry;
        sort(S.begin(),S.end());
        
        dfs(S,0,entry,res);
        return res;
    }
    void dfs(vector<int>S, int index, vector<int> &entry, vector<vector<int> > &res){
        if(index >= S.size()) return;
        
        for(int i= index; i < S.size(); i++){//[]; 1; 1,2; 1,2,2; 2; 2,2;...
            if(i != index && S[i] == S[i-1]) continue;
            entry.push_back(S[i]);
            res.push_back(entry);
            dfs(S,i+1,entry,res);
            entry.pop_back();
        }
    }