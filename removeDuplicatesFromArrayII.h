    int removeDuplicates(int A[], int n) {
        int start = 0, end = 0, count = 0;
        
        while(end < n){ //when it is a new element or count < 2, keep this element, otherwise loop forward
             if(start == 0 || A[end] != A[end-1]){
                 count = 1;
                 A[start++] = A[end];
             }  
             else{
                 if(count < 2){
                     A[start++] = A[end];
                     count++;
                 }
             }
             end++;
        }
        return start;
    }

    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int j = 2;
        for (int i = 2; i < n; ++i)
            if (A[i] != A[j-2])
                A[j++] = A[i];
        return j;
    }