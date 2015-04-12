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
    //dp : plusOne
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        unordered_map<int, vector<vector<int> > > map;
        
        if (candidates.size() == 0) return ret;
        sort(candidates.begin(), candidates.end());
        ret.resize(1);
        map[0] = ret;
        
        for (int i = 0; i < candidates.size(); i++)
          for (int j = 1; j <= target; j++) {
            if (candidates[i] <= j && map.count(j - candidates[i]) != 0) {
              for(const auto& x : map[j - candidates[i]]){
                vector<int> y = x;
                y.push_back(candidates[i]);
                map[j].push_back(y);
              }
            } 
          }
        return map[target];
    }