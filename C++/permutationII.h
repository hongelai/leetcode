    vector<vector<int> > res;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        
        vector<int> entry;
        int size = num.size();
        vector<bool> visit(size,false);
        sort(num.begin(),num.end());
        dfs(0,size,num,entry,visit);
        return res;
    }
    void dfs(int deep, int size, vector<int> &num, vector<int> &entry, vector<bool> &visit){ 
        // use 'visit' array to check available num
        if(deep == size){
            res.push_back(entry);
            return;
        } 
        //在同一个迭代层相同的数跳过，不同迭代层的相同的可以加上，所以lastIndex每一层都从新开始算
        int lastIndex = -1;
        for(int i = 0; i < size; i++){
            if(lastIndex != -1 && num[lastIndex] == num[i]) continue;
            if(!visit[i]){
                entry.push_back(num[i]);
                visit[i] = true;
                dfs(deep+1,size,num,entry,visit);
                visit[i] = false;
                entry.pop_back();
                lastIndex = i;
            }
        }
    }

    //complexity O(2^n)
    //T(n) = n*(T(n) + O(1))