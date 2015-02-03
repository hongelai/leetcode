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