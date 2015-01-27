    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        if(target <= 0) return res;
        vector<int> entry;
        int size = num.size();
        sort(num.begin(),num.end());
        
        dfs(0, 0, size, entry, res, num, target);
        return res;
    }
    void dfs(int sum, int index, int size, vector<int> &entry, vector<vector<int> > &res, vector<int> &num, int target){
        if(sum == target){
            res.push_back(entry);
            return;
        }
        
        for(int i = index; i < size; i++){
            if(i !=  index && num[i] == num[i-1]) continue; // avoid using same num in the same for loop,ie. {1,1}, 1
            if(sum + num[i] > target) break;
            entry.push_back(num[i]);
            dfs(sum + num[i], i+1, size, entry,res,num,target);
            entry.pop_back();
        }
    }