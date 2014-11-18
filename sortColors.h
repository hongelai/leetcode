    void sortColors(int A[], int n) {
        int front = 0,back = n-1;
        for(int i =0; i <=back && i >= front;){
            
            if(A[i]==0)      swap(A[i++],A[front++]); //0前面只会是0或者 1，所以0交换后只会是1
            else if(A[i]==2) swap(A[i],A[back--]);    //2交换后可能是0，1 或者2，所以 i不要变
            else             i++;
        }
    }