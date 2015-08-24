    int titleToNumber(string s) {
        
        int size = s.size(),index = 0,sum = 0;
        
        while(index < size){
            sum = (s[index++] - 'A' + 1) + sum*26;
        }
        return sum;
    }