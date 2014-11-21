    int threeSumClosest(vector<int> &num, int target) {
        int res, gap = INT_MAX, size = num.size();
        sort(num.begin(),num.end());
        for(int i = 0; i < size-2; i++){
            int pre = i+1,last = size-1;
            
            while(pre < last){
                
                if(abs(num[i]+num[pre]+num[last]-target) < gap ){
                    gap = abs(num[i]+num[pre]+num[last]-target);
                    res = num[i]+num[pre]+num[last];
                    if(res > target) last--;
                    else if(res < target)pre++;
                    else return res;
                    //这里不能再去重，上面不是同时pre++，last--， 这里再处理，可能会删掉不必要的
                }else{
                    if(num[i]+num[pre]+num[last] < target) pre++;
                    else last--;
                   
                }
            }
        }
        return res;
    }