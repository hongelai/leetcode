   //k-SUM 的解法 先固定其中的k-2个值，剩下的2个值动态查找匹配的，最优解永远是O(n^k-2)
    //这是边跑边去重
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        int size = num.size();
        if(size < 3) return ret;
        sort(num.begin(),num.end());    //排序后可以夹逼求值
        
        for (int i = 0; i < size - 2; i++) {
            if (i > 0 && num[i] == num[i-1]) continue;
            int start = i + 1, end = size - 1;
            while (start < end) {
                if (num[i] + num[start] + num[end] > 0) end--;
                else if (num[i] + num[start] + num[end] < 0) start++;
                else {
                    ret.push_back({num[i], num[start], num[end]});
                    start++;
                    end--;
                    while (start < end && num[start-1] == num[start]) start++;
                    while (start < end && num[end+1] == num[end]) end--;
                }
            }
        }
        return ret;
    }