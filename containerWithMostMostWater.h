    int maxArea(vector<int> &height) {
        if(height.size() < 2) return 0;
        int start = 0,end = height.size()-1;
        int res = INT_MIN;
        while(start < end){
            int shorter = min(height[start],height[end]);
            res = max(res,shorter*(end-start));
            height[start] < height[end] ? start++:end--; //每次只需要把当前的短板更换
        }
        return res;
    }