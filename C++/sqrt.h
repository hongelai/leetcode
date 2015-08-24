    int sqrt(int x) {
        //sqrt(x) will not bigger than x/2 + 1
        if(x == 0) return 0;
        int low = 1, high = x;
        
        while(low < high){
            int mid = (low + high) / 2;
            if(x / mid > mid){ //use division to avoid overflow
                if(x / (mid+1) < mid+1) return mid;
                else low = mid + 1;
            }else if( x / mid < mid) high = mid - 1;
            else return mid;
        }
        return low;
    }

    int sqrt(int x) {
        //sqrt(x) will not bigger than x/2 + 1
        if(x == 0) return 0;
        int low = 1, high = x;
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(x / mid > mid){ //use division to avoid overflow
                low = mid + 1;   //low 可能会比实际 应该返回的值 大 1， 但是 此后 high 会不断减小直至和low相等，high 会再减掉1 ，所以返回的值 正确的
            }else if( x / mid < mid) high = mid - 1;
            else return mid;
        }
        return high;
    }