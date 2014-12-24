    string convertToTitle(int n) {
        
        string res="";
        while(n){
            int mod = n%26;
            if(mod == 0){
                mod = 26;
                n = n/26 - 1;
            }else{
                n /= 26;
            }
            res = (char)(mod + 64) + res;
        }

        return res;
    }

// n-1 to handle corner case 26
    string convertToTitle(int n) {
        
        string res="";
        while(n){
            res = (char)((n-1)%26 + 'A') +res;
            n = (n-1) / 26;
        }

        return res;
    }