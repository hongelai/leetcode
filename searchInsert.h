    int searchInsert(int A[], int n, int target) {
        int i;
        for(i = 0; i < n; i++)
            if(A[i] >= target)
                return i;
        if(i == n) return n;
    }