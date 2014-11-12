    int romanToInt(string s) {
        unordered_map<char,int> um;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        int result = 0;
        
        for(auto it = s.begin(); it != s.end();it++){
            char c = *prev(it);
            if(um[*it] > um[c]) result += um[*it] -2*um[c]; //左减数只能一位， 上升说明 为减， *2 把前面错加的一块减掉 
            else result += um[*it];
        }
        return result;
    }