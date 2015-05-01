    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<bool> prime(n,true);
        int count = 0;
        
        for(int i = 2; i < n; i++){
            if(prime[i]){
                count++;
                for(int j = i+i; j < n; j+=i) prime[j] = false; //把倍数去设为false
            }
        }
        return count;
    }