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

    int trap_2(int A[], int n) {
        if (A == NULL || n <= 2) return 0;
        int left= 1;
        int right = n - 2;
        int maxLeft = A[0];
        int maxRight = A[n - 1];
        int res = 0;
        while (left <= right) {  //因为最终的计算还是以最短板为准，所以可以不用存起来所有结果，而是每次处理短板一边的。
            if (maxLeft <= maxRight) {
                res += max(0, maxLeft - A[left]);
                maxLeft = max(maxLeft, A[left]);
                ++left;
            } else {
                res += max(0, maxRight - A[right]);
                maxRight = max(maxRight, A[right]);
                --right;
            }
        }
        return res;
    }