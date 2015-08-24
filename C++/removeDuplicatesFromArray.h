    int removeDuplicates(int A[], int n) {
        if(n < 2) return n;
        int sIdx = 1;
        for(int i =1; i < n; i++){
            if(A[i] != A[i-1]){
                A[sIdx++] = A[i];
            }
        }
        return sIdx;
    }
    int removeDuplicates(int A[], int n) {
        if(n == 0) return 0;
        int start = 0, end = 0;
        while(end < n) {
            if (A[start] != A[end]) A[++start] = A[end];
            end++;
        }
        return start + 1;
    }