    bool canJump(int A[], int n) {
        if(n <= 1) return true;
        int left = A[0];
        
        int i = 0;
        for(; i < n; i++){
            if(0 == i) left = A[0];
            else left = left - 1 > A[i] ? left - 1 : A[i];
            if(left > 0) continue;
            else    break;
            
        }
        if((i == n || i == n-1) && left >= 0) return true;
        else return false;
    }

    bool canJump(int A[], int n) {
        int start = 0, end = 0;
        while (start <= end && end < n-1)
        {
            end = max(end, start + A[start]);
            start++;
        }
        return end >= (n-1);
    }