
    int maxProduct(int A[], int n) {
        if(n == 0) return 0;
        
        int maxRes = A[0], minRes = A[0],result = A[0];
        for(int i = 1; i < n; i++){
            int tempMax = maxRes;
            //包含第i 的三种情况，A[i]本身， max* A[i]， min*A[i]
            maxRes = max(A[i],max(minRes*A[i],A[i]*maxRes));
            minRes = min(A[i],min(minRes*A[i],A[i]*tempMax));
            if(maxRes > result){
                result = maxRes;
            }
        }
        return result;
    }