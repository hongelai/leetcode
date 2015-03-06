    int findMin(vector<int> &num) {
        int start = 0;
        int size = num.size();
        int end = size-1;
        
        while(start < end){
            if(num[start] < num[end]) return num[start];
            int mid = (start+end)/2;
            if(num[start] < num[mid]) start = mid+1;
            else if(num[start] >num[mid]) end = mid;
            else start++;
            
        }
        return num[start];
    }