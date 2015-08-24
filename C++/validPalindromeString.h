    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        if(s.size() == 0 )return true;
        int low = 0;
        int high = s.size()-1;
        
        while(high > low){
            while(!isalnum(s[low]) && high>low) low++;
            while(!isalnum(s[high]) && high>low) high--;
            if(s[high] != s[low]) return false;
            high--;
            low++;
        }
        return true;
    }