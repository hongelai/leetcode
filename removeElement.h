    int removeElement(int A[], int n, int elem) {
        if(n == 0) return 0;
        int i = 0;
        for(int j = n-1; i < j; ){
            if(A[i] == elem) swap(A[i],A[j--]);
            if(A[i] != elem) i++;
        }
        for(i = 0; A[i] != elem && i < n; i++);
        return i;
    }

    int removeElement(int A[], int n, int elem) {
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != elem) {
                A[index++] = A[i];
            }
        }
        return index;
    }

    int removeElement(int A[], int n, int elem) {
        if (n == 0) return 0;
        int start = 0, end = n-1;
        while (start <= end) {
           if (A[start] == elem) {
               swap(A[start], A[end--]);
           } else start++;
        }
        return end + 1;
    }