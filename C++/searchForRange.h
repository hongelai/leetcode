    vector<int> searchRange(int A[], int n, int target) {
        
        int start = 0,end = n-1,mid=0;
        vector<int> res;
        while(start <= end){
            mid = (start+end)/2;
            if(A[mid] > target) end = mid -1;
            else if(A[mid] < target) start = mid +1;
            else break;
        }
        if(A[mid] == target){
               int left, right;
               left = right = mid;
               while(left-1 >= 0 && A[left-1] == target) left--;
               while(right+1 < n && A[right+1] == target) right++;
               res.push_back(left);
               res.push_back(right);
               return res;
               
        }else{
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
    }