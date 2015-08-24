    void merge(int A[], int m, int B[], int n) {
        int aidx = m-1,bidx = n-1;
        int i = m+n-1;
        
        for(; i >= 0 && aidx >=0 && bidx >=0; i--){
            if(A[aidx] > B[bidx]){  // A[i] = A[aidx] >= B[bidx] ? A[aidx--]:B[bidx--]; 
                 A[i] = A[aidx];
                 aidx--;
            }else{
                A[i] = B[bidx];
                bidx--;
            }
        }
        for(;bidx >=0; bidx--) A[i--] = B[bidx];
    }