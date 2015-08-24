    int search(int A[], int n, int target) {
        if(n < 1) return -1;
        int start = 0, end = n-1;
        
        while(start <= end){
            int mid = (start + end) / 2;
            if(A[mid] == target){
                return mid;
            }else if(A[start] <= A[mid]){
                if(target >= A[start] && target < A[mid]){ //4,5, | 6,0,1,2,3 always consider the stable part first
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }   
            }else{
                if(target > A[mid] && target <= A[end]){ // 4,5,6,0, | 1,2,3 consider the stable part->right part
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }