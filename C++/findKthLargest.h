    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestRe(nums,0,nums.size(),nums.size()-k+1);
    }
    int findKthLargestRe(vector<int>& nums, int start, int end, int k) {
        int pos;
        pos = partition(nums, start, end);
        if (pos == k-1) return nums[pos];
        else if(pos > k-1) findKthLargestRe(nums, start, pos-1, k);
        else findKthLargestRe(nums,pos+1, end,k);
    }
    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[start];
        int i = start+1;
        for(int j = i; j < nums.size();j++){
            if(nums[j] < pivot) {
                swap(nums[j],nums[i++]);
            }
        }
        swap(nums[start],nums[i-1]);
        return i-1;
    }