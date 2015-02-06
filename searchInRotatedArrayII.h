    bool search(int A[], int n, int target) {
        if(n < 1) return false;
        int start = 0, end = n - 1;
        
        while(start <= end){
            int mid = (start+end)/2;
            if(target == A[mid]) return true;
            else if(A[start] < A[mid]){   // increasing
                if(target >= A[start] && target < A[mid]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }else if(A[start] > A[mid]){
                if(target > A[mid] && target <= A[end]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }else{ // cannot determine if it is increasing or not  1 3 1 1 1 1 1
                start++;  //skip this duplicate
            }
        }
        return false;
    }