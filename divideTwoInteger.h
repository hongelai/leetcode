    int divide(int dividend, int divisor) {
        //bottom up, subtract divisor. if still available =, double divisor and subtract
        bool negative = (dividend > 0) ^ (divisor > 0);
        long long a = abs((long long)dividend), b = abs((long long)divisor);
        long long res = 0;
        
        while(a >= b){ // use  minus to subtract divisor and double it to speed up
            long long c = b;
            
            for(int i = 0; c << i <= a; i++){ //double divisor 
                a -= c << i;
                res += 1 << i;
            }
        }
        res = negative ? -res: res;
        return res > INT_MAX ? INT_MAX: res;
    }