    // .* matches ab because .* == .. = ab
    bool isMatch(const char *s, const char *p) {
        if(*p =='\0') return *s =='\0';
        
     
        if(*(p+1) == '*'){
            //* 的作用，P能匹配：匹配0个，进入下一阶段子集；匹配1个，进入子集；匹配2个。。。。
            //匹配不上， 直接进入下一阶段匹配
            while((*p == '.' && *s != '\0') || *s == *p){ 
               if(isMatch(s,p+2)) return true;
               s++;
            }
            return isMatch(s,p+2); // ab ----- c*ab
            
        }else{
            if((*p == '.' && *s != '\0') || *s == *p) return isMatch(s+1,p+1);
            else return false;
        }
    }


    /**
     * b[i + 1][j + 1]: if s[0..i] matches p[0..j]
     * if p[j] != '*'
     * b[i + 1][j + 1] = b[i][j] && s[i] == p[j]
     * if p[j] == '*', denote p[j - 1] with x,
     * then b[i + 1][j + 1] is true iff any of the following is true
     * 1) "x*" repeats 0 time and matches empty: b[i + 1][j -1]
     * 2) "x*" repeats 1 time and matches x: b[i + 1][j]
     * 3) "x*" repeats >= 2 times and matches "x*x": s[i] == x && b[i][j + 1]
     * '.' matches any single character
     */
     bool isMatch(const char *s, const char *p) {
        int i, j;
        int m = strlen(s);
        int n = strlen(p);

        bool b[m + 1][n + 1];
        b[0][0] = true;
        for (i = 0; i < m; i++) {
            b[i + 1][0] = false;
        }
        // p[0..j - 2, j - 1, j] matches empty iff p[j] is '*' and p[0..j - 2] matches empty
        for (j = 0; j < n; j++) {
            b[0][j + 1] = j > 0 && '*' == p[j] && b[0][j - 1];
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (p[j] != '*') {
                    b[i + 1][j + 1] = b[i][j] && ('.' == p[j] || s[i] == p[j]);
                } else {
                    b[i + 1][j + 1] = b[i + 1][j - 1] && j > 0 || b[i + 1][j] ||                 //前两种情况，‘c*’ 中， 第一种 c*都不匹配，跳过；第二种，只匹配 c， *跳过
                                b[i][j + 1] && j > 0 && ('.' == p[j - 1] || s[i] == p[j - 1]);   //第三种情况， c* 都匹配
                }
            }
        }
        return b[m][n];
    }