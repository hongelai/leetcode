    int atoi(const char *str) {
        int i = 0;
        bool flag = false, positive = true;
        while(str[i] == ' ') i++;
        if(str[i] == '+' || str[i] == '-') flag = true;
        if(flag == true){
            
            if(str[i] == '-') positive = false;
            i++;
        }
        if(str[i] < '0' || str[i] > '9' ) return 0;
        stack<int> res;
        while(str[i] >='0' && str[i] <= '9') res.push(str[i++]-'0');
          
        
        long long result = 0;
        for(int j =0; !res.empty();j++){
            int it = res.top();
            result+= it * pow(10,j);
            res.pop();
            if(positive && result > INT_MAX){
                result = INT_MAX;
                return (int)result;
            } 
            if(!positive && 0 - result < INT_MIN){
                result = INT_MIN;
                return (int)INT_MIN;
            } 
        } 
    
        if(flag && !positive) return 0-result;  
        else return result;
    }