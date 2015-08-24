    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if(!numerator) return "0";
        
        if((numerator>0) ^ (denominator >0)) res.push_back('-');
        long long n = abs((long long)numerator), d = abs((long long)denominator); //prevent overflow when devide
        
        res.insert(res.size(),to_string(n/d));
        n = n%d;
        if(!n) return res;
        else res.push_back('.');
        
        unordered_map<int,int> map; // store numerator-position pair
        for(int i = res.size(); n != 0;i++){
            if(map.count(n)) break;  //if same numerator occur, means repeating
            map[n] = i;
            n *= 10;
            res.push_back(n/d+'0');
            n %= d;
        }
        if(n){
            res.insert(map[n],"(");
            res.push_back(')');
        }
        
        return res;
    }