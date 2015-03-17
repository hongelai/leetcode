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

    //思路：不断切半，只要start < end, A[start] < target && A[end] > target, 等start》end的时候, start 就是目标位置了
    int searchInsert(int A[], int n, int target) {
        int start = 0, end = n-1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (A[mid] > target) {
                end = mid - 1;
            } else if (A[mid] < target) {
                start = mid + 1;
            } else {
                return mid ;
            }
        }
        return start;
    }