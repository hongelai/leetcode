    int minSubArrayLen(int s, vector<int>& nums) {//use sliding window
        int index = 0, sum = 0, minLen = INT_MAX; 
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while(sum >= s){
                minLen = min(minLen, i - index + 1);
                sum -= nums[index++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }