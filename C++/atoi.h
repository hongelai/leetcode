    int myAtoi(string str) {
        int len = str.length(), i = 0;
        bool positive = true;
        if(len == 0) return 0;
        while(str[i] == ' ') i++;
        if (str[i] == '+' || str[i] == '-') {
            if(str[i] == '-') positive = false;
            i++;
        }
        queue<int> q;
        while(str[i] - '0' >= 0 && str[i] - '0' <= 9) {
            q.push(str[i++]- '0');
        }
        long long res = 0;
        
        for (int j = 0; !q.empty(); j++){
            res = res * 10 + q.front();
            q.pop();
            if(positive && res > INT_MAX) {
                return INT_MAX;
            } 
            if(!positive && 0 - res < INT_MIN) {
                return INT_MIN;
            }
        }
        if(!positive) return 0-res;
        else return res;
    }