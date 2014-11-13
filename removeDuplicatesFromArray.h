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