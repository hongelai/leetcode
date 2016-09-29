public class Solution {
    public int divide(int dividend, int divisor) {
        boolean positive = dividend > 0 ^ divisor > 0;
        long a = Math.abs((long)dividend);
        long b = Math.abs((long)divisor);
        long ret = 0;
        
        while (a >= b) {
            long c = b;
            for (int i = 0; (c << i) <= a; i++) {
                a -= c<<i;
                ret += 1<<i;
            }
        }
        if (positive) ret = -ret; 
        return ret >= Integer.MAX_VALUE ? Integer.MAX_VALUE : (int)ret; 
    }
}