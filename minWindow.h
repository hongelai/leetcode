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