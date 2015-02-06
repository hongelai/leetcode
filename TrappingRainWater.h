    int trap(int A[], int n) { // scan from left to right and then right to left, get the min value as peak
        vector<int> maxLeft(n,0);
        vector<int> maxRight(n,0);
        int res = 0;
        for(int i = 1, j = n-2; i < n; i++, j--){
            maxLeft[i] = max(maxLeft[i-1],A[i-1]);
            maxRight[j] = max(maxRight[j+1],A[j+1]);
        }
        for(int i = 0; i < n; i++){
            int high = min(maxLeft[i],maxRight[i]);
            if(high > A[i]) res += high - A[i];
        }

        return res;
    }