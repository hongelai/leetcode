    int searchInsert(int A[], int n, int target) { //O(n)
        int i;
        for(i = 0; i < n; i++)
            if(A[i] >= target)
                return i;
        if(i == n) return n;
    }
    int searchInsert(int A[], int n, int target) { //O(log(n))
        if(n==0) return 0;
        int start = 0;
        int end = n-1;
        int mid = 0;
        while(start < end){
            mid = (start+end)/2;
            if(A[mid] < target) start = mid+1;
            else end = mid;
        }
        if(A[start] >= target) return start; // start == end after the while loop
        if(A[start] < target) return start+1;
    }