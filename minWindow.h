   //two pointer , once the first pointer find all needed characters, 
   //move the second pointer to shrink the range.
    string minWindow(string S, string T) {
        int M = S.size(),N = T.size();
        if(M < N) return "";
        int need[256] = {0}, find[256] = {0};
        
        int start, end,rstart = -1,rend = M,count=0;
        start = end = 0;
        
        for(int i = 0; i < N; i++) need[T[i]]++;

        for(int i = 0; i < M; i++,end++){
            if(!need[S[i]]) continue;
            
            find[S[i]]++;
            if(find[S[i]] <= need[S[i]]) count++;
            if(count == N){ //find all needed characters
                for(;start <= end; start++){
                    if(!find[S[start]]) continue;
                    if(find[S[start]] <= need[S[start]]) break;
                    find[S[start]]--;
                }
                //update rstart , rend
                if(end- start < rend - rstart){
                    rstart = start;
                    rend = end;
                }
            }
            
             
        }
        return rstart == -1? "":string(S.begin()+rstart,S.begin()+rend+1);
    }

    //
    string minWindow(string S, string T) {
        int sLen = S.length(), tLen = T.length();
        int start = 0, end = 0, count = 0, minLen = INT_MAX;
        string ret = "";
        int need[256] = {0}, find[256] = {0};
        
        if (sLen < tLen) return ret;
        for(int i = 0; i < tLen; i++) need[T[i]]++;
        
        while (end < sLen) {
            if (need[S[end]] == 0){
                end++;
                continue;
            } 
            find[S[end]]++;
            if (find[S[end]] <= need[S[end]]) count++;
            
            if (count == tLen) {
                while (need[S[start]] == 0 || need[S[start]] < find[S[start]]) {
                    find[S[start]]--;
                    start++;
                }
                int len = end - start + 1;
                if (minLen > len) {
                    minLen = len;
                    ret = S.substr(start, len);
                }
            }
            end++;
        }
        return ret;
    }