
        for(int i = 0; i < n; ){
            if(A[i]>0 && A[i]<=n && A[i] != i+1 && A[i]!=A[A[i]-1])
                swap(A[i],A[A[i]-1]);
            else i++;
        }
        for(int i = 0; i < n; i++){
            if(A[i] != i+1) return i+1;
        }
        return n+1;

   //上面只是寻找从1开始 缺失的第一个整数， 假如从任意正整数开始缺失的第一个整数呢？
	//aws：寻找最小的正整数，映射到1；
    int firstMissingPositive(int A[], int n) {
        int minInt =numeric_limits<int>::max();
        for(int i =0; i<n;i++){
            if(A[i] >0) minInt = min(minInt,A[i]);
        }
        if(minInt ==numeric_limits<int>::max() ) return 1;
        
        for(int i =0; i<n;i++)
            A[i] =A[i]-minInt+1;
    
        for(int i = 0; i < n; ){
            if(A[i]>0 && A[i]<=n && A[i] != i+1 && A[i]!=A[A[i]-1])
                swap(A[i],A[A[i]-1]);
            else i++;
        }

        for(int i = 0; i < n; i++){
            if(A[i] != i+1) return i+minInt;
        }
        return n+1+minInt;
        

    }