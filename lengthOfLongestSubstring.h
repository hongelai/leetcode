    int lengthOfLongestSubstring(string s) {
        int res = 0;
        vector<int> asci(256,-1);
        int start = 0,end = 0,size = s.length();
        
        while(end < size && start+res < size){
            if(asci[s[end]] == -1){
                asci[s[end++]] = end;
            }else{ //conflict occcurs
                res = max(end - start,res);
                int old_start = start;
                start = asci[s[end]]+1;    // move start pointer to first occurence of the conflict character
                while(old_start < start){  //clear the asci array till the new start
                    asci[s[old_start++]] = -1;
                }
            }
        }
        if(!s.empty())    //add the tail case
            res = max(end - start,res);
        return res;
    }