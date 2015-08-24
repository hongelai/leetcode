    int singleNumber(int A[], int n) {
        //solution one: use count[32] to count the bit occurrence of each bit, find out those bit occurrence cannot be devide by 3
        int W = sizeof(int)*8;
        vector<int> count(W,0);
        int res = 0;
        
        for(int i = 0; i < W; i++){
            for(int j = 0; j < n; j++){
                if((A[j]>>i)&1) count[i]++; //first bit >>0, second bit >>1
            }
            res |= count[i]%3 << i;
        }
        
        // for(int k = W-1; k >= 0; k--) res += (count[k]%3) << k;
        return res;
    }
    int singleNumber(int A[], int n) {
        //solution 2: use one two three to simulate unary, binary, and triple number system
        int one = 0, two = 0, three = 0;
        
        for(int i = 0; i < n; i++){
            two |= one & A[i];
            one ^= A[i];
            three = one & two;
            one &= ~three;
            two &= ~three;
        }
        return one;
    }