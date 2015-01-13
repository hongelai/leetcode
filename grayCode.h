//http://blog.csdn.net/beiyeqingteng/article/details/7044471
//grayCode --> binary Bi = Gi XOR Bi+1
//binary-->graycode  Gi = Bi XOR Bi+1
    vector<int> grayCode(int n) {
        vector<int> res(1<<n);
        for(int i = 0; i < 1<<n; i++)
            res[i] = (i >> 1) ^ i; //GrayCode(n) = B(n) XOR B(n+1). B(n)表示n的二进制，B(n+1)表示n右移一位的二进制

        return res;
    }
//recursive
