    int maxSubArray(int A[], int n) {
        //for each num, it will join the previous subarray or initial a new one.
        //when the previous subarray < 0 , it harms the result, in this condition, we should initial a new one
        if(n <= 0) return 0;
        
        int res = A[0],sum = A[0];
        for(int i = 1; i < n; i++){
            sum = sum < 0 ? A[i] : sum+ A[i];
            res = max(res, sum);
        }
        return res;
    }