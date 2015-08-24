    string getPermutation(int n, int k) {
        vector<int> num;
        int total = 1;
        string res= "";
        for(int i = 1; i <= n; i++){
            num.push_back(i);
            total *= i;   //calculate total permutation f(n) = f(n-1) * n
        }
        k--;
        while(n){
            total /= n;   
            int index = k / total;
            res.push_back(num[index] + '0');
            num.erase(num.begin()+index);
            k %= total;
            n--;
        }
        return res;
    }