    bool isScramble(string s1, string s2) {
        int len = s1.length();
        return dfs(s1.begin(), s1.end(), s2.begin(), s2.end());
    }
    bool dfs(string::iterator f1, string::iterator e1, string::iterator f2, string::iterator e2){
        int len = e1 - f1;
        if (!hasSameLetters(f1,f2,len)) return false;
        if(len == 1) return *f1 == *f2;
        
        for(int i = 1; i < len; i++){
            if ((dfs(f1, f1+i, f2, f2+i) && dfs(f1+i, e1, f2+i, e2)) || 
                   (dfs(f1, f1+i, e2-i, e2) && dfs(f1+i, e1, f2, e2-i)))
            return true;
        }
        return false;
    }
     bool hasSameLetters(string::iterator s1, string::iterator s2, int len) {
        int count[256] = {0};
        for (int i = 0; i < len; ++i) count[*s1++]++;
        for (int i = 0; i < len; ++i) count[*s2++]--;
        for (int i = 0; i < 256; ++i)
            if (count[i] != 0) return false;
        return true;
    }

    //dp
        bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int len = s1.length();
        bool dp[len+1][len][len];//dp[k][i][j] means s1.substr(i,k) is scramble string of s2.substr(j,k)
        fill_n(&dp[0][0][0],(len+1)*len*len,false);
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                dp[1][i][j] = s1[i] == s2[j] ? true : false;
        
        for (int k = 2; k <= len; k++) {
            for (int i = 0; i + k <= len; i++) {
                for (int j = 0; j + k <= len; j++) {
                    for (int r = 1; r < k; r++) {
                        if ((dp[r][i][j] && dp[k-r][i+r][j+r]) || (dp[r][i][j+k-r] && dp[k-r][i+r][j]))
                        {
                            dp[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
       return dp[len][0][0]; 
    }