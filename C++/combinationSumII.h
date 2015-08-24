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



     vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<int> numbers = num;
        sort(numbers.begin(), numbers.end());

        vector<vector<int>> result;
        vector<int> indices;  // store the indices of the numbers of a combination in non-descending order
        int i = 0;
        while (i < numbers.size()) {
            if (target == numbers[i]) {
                vector<int> subset;
                subset.reserve(indices.size() + 1);  // avoid memory reallocations
                for (int j : indices) subset.push_back(numbers[j]);
                subset.push_back(target);
                result.push_back(move(subset));  // move instead of copy
            }
            // Note: numbers.back() is the maximum
            if (target <= numbers[i] ||
                    (target > numbers[i] && i == numbers.size() - 1) ||
                    (target > numbers.back() * (numbers.size() - i))) {
                if (indices.empty()) return result;
                // pop the last added number and update the target number
                i = indices.back() + 1;
                target += numbers[i-1];
                indices.pop_back();
                // avoid duplicates
                while (i >= numbers.size() || numbers[i-1] == numbers[i]) {
                    if (i >= numbers.size()) {
                        if (indices.empty()) return result;
                        i = indices.back() + 1;
                        target += numbers[i-1];
                        indices.pop_back();
                    } else {
                        i++;  // ignore the same numbers
                    }
                }
            } else {
                target -= numbers[i];
                indices.push_back(i);
                i++;
            }
        }
        return result;
    }