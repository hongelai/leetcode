    int findPeakElement(const vector<int> &num) {
        int low = 0, high = num.size()-1;
        if(num.size() <=1 || num[0] > num[1]) return 0;
        if(num[high] > num[high-1]) return high;
        low = 1; high = high-1;
        
        while(low < high){
            int mid = (low + high) / 2;
            if(num[mid] > num[mid-1] && num[mid] > num[mid+1]) return mid;
            else if(num[mid] > num[mid+1]) high = mid-1;
            else low = mid+1;
        }
        return low;
    }