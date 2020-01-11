class Solution {
    
    // divide and conquer
    public double myPow(double x, int n) {
        
        long N = n;
        if (n < 0) {
            x = 1/x;
            N = -N;
        }
        return pow(x, N);
    }
    
    private double pow(double x, long n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        
        double half = pow(x, n/2);
        double remain = pow(x, n%2);
        return half*half*remain;
    }
}