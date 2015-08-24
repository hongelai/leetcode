    int jump(int A[], int n) {
        //jump to the position you can jump farthest
        int start = 0, end = 0;
        int step = 0;
        while(start <= end && end < n-1){
            end = max(end, start + A[start]);
            if(end >= n-1){
                step++;
                break;
            }
            int maxIndex = start;
            for(int i = start; i <= end; i++){
                if(maxIndex + A[maxIndex] < i + A[i]) maxIndex = i;
            }
            step++;
            start = maxIndex;
        }
        return step;
    }