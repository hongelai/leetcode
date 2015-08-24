    int numTrees(int n) {
        //f(n) = f(0)*f(n-1) + f(1)*f(n-2)+....+f(n-1)*f(0), root = n，左子树 * 右子树 root= n-1，。。。。
        vector<int> f(n+1,0);
        f[0] = 1; f[1] = 1;
        
        for(int i = 2; i <= n; i++)
            for(int j = 0; j < i; j++) // calculate f(2),...f(n)
            {
                f[i] += f[j] * f[i-j-1];
            }
        return f[n];
    }