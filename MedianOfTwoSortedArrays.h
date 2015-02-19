    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2 == 0) return ((double)findKthNumber(A, m, B, n, (m+n)/2) + findKthNumber(A, m, B, n, (m+n)/2 + 1)) / 2;
        else return findKthNumber(A, m, B, n, (m+n)/2 + 1);
    }
    int findKthNumber(int A[], int m, int B[], int n, int k){
        assert(k <= m+n && k);
        if(m == 0 && n >= k) return B[k-1];
        if(n == 0 && m >= k) return A[k-1];
        if(k == 1) return min(A[0], B[0]);
        int h = k/2;
        int asub = min(m, h);
        int bsub = min(n, h);
        if(A[asub-1] > B[bsub-1]) return findKthNumber(A, m, B+bsub, n-bsub, k-bsub);//cut off B 0-bsub
        else return findKthNumber(A+asub, m-asub, B, n, k-asub); // cut off A 0-asub
    }
    //another find kth ,more unstandable
      double findKthSortedArrays(int A[], int m, int B[], int n, int k) {
        if (m > n)
            return findKthSortedArrays(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);

        int i = min(k / 2, m);
        int j = k - i;
        int a = A[i-1];
        int b = B[j-1];

        if (a < b) return findKthSortedArrays(A + i, m - i, B, n, k - i);
        else if (a > b) return findKthSortedArrays(A, m, B + j, n - j, k - j);
        else return a;
    }