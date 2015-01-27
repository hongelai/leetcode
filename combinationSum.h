    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        if(target <= 0) return res;
        vector<int> entry;
        int size = candidates.size();
        sort(candidates.begin(),candidates.end());
        
        dfs(0, 0, size, entry, res, candidates, target);
        return res;
    }
    void dfs(int sum, int index, int size, vector<int> &entry, vector<vector<int> > &res, vector<int> &candidates, int target){
        if(sum == target){
            res.push_back(entry);
            return;
        }
        
        for(int i = index; i < size; i++){
            if(sum + candidates[i] > target) break;
            entry.push_back(candidates[i]);
            dfs(sum + candidates[i], i, size, entry,res,candidates,target);
            entry.pop_back();
        }
    }