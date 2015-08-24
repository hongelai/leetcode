/* The basic idea is to find the leftmost bit at which m and n are different. 
Then just keep [i+1, 31] bits and reset [0,i] bits of m to zero*/
//因为除了相同的前缀 其他位在AND过程中都会遇到0 被设成0
     int rangeBitwiseAnd(int m, int n) {
        if(m==0) return 0;
        if(m==n) return m;
        int res = 0,i;
        for (int i = 31; i >= 0; i--){
            int bit = 1 << i;
            if((n & bit) > 0){
                if((bit & m) == 0) break;
                res |= bit;
            }
            
        }
        
        return res;
    }