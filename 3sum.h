   //k-SUM 的解法 先固定其中的k-2个值，剩下的2个值动态查找匹配的，最优解永远是O(n^k-2)
    //这是边跑边去重
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        if(num.size() < 3) return res;
        sort(num.begin(),num.end());
        int target = 0;
        
        for(int i = 0; i < num.size()-2; i++){
            if(num[i] == num[i-1]) continue;
            
            int pre = i+1, last = num.size()-1;

            while(pre < last){
                if(num[i]+num[pre]+num[last] > target){
                    last--;
                }else if(num[i]+num[pre]+num[last] < target){
                    pre++;
                }else{
                    res.push_back({num[i],num[pre],num[last]});
                    last--;
                    pre++;
                    //找到一个值后进入下一个迭代，当其中任意一个和前面相同时，跳过该值
                    while(pre < last && num[last] == num[last+1])  last--; 
                    while(pre < last && num[pre] == num[pre-1])  pre++;
                }
            }
            
        }
        
        return res;
    }