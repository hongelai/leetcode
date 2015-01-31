    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> entry;
        int size = num.size();
        vector<bool> visit(size,false);
        dfs(0,size,num,entry,visit,res);
        return res;
    }
    void dfs(int deep, int size, vector<int> &num, vector<int> &entry, vector<bool> &visit, vector<vector<int> > &res){ 
        // use 'visit' array to check available num
        if(deep == size){
            res.push_back(entry);
            return;
        }
        for(int i = 0; i < size; i++){
            if(!visit[i]){
                entry.push_back(num[i]);
                visit[i] = true;
                dfs(deep+1,size,num,entry,visit,res);
                visit[i] = false;
                entry.pop_back();
            }
        }
    }