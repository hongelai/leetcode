    double pow(double x, int n) {
        //divide and conquer x^n = x^n/2 * x^n/2 *x^n%2
        if(n == 0) return 1;
        if(n == 1) return x;
        bool flag = false;
        if(n < 0){
            n = -n;
            flag = true;
        }
        double half = pow(x, n/2);
        double remain = pow(x, n % 2);
        if(!flag)
            return half * half * remain;
        else return 1 / (half * half * remain);
    }