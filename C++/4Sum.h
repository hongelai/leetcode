    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if(num.size() < 4) return res;
        int size = num.size();
        sort(num.begin(),num.end());
        
        for(int i = 0; i < size-3;i++){
            for(int j = i+1; j < size -2; j++){
                int pre = j+1,last = size-1;
                while(pre < last){
                    if(num[i]+num[j]+num[pre]+num[last] > target) last--;
                    else if(num[i]+num[j]+num[pre]+num[last] < target) pre++;
                    else{
                        res.push_back({num[i],num[j],num[pre],num[last]});
                        pre++;
                        last--;
                        while(pre < last && num[pre] == num[pre-1]) pre++;
                        while(pre < last && num[last] == num[last+1]) last--; 
                    }
                }
            }
        }
        //4sum最后还要去重一下，因为for loop选了两个值，会重复，for选的值也会和while选的值重复
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
        
    }