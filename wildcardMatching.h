    bool isMatch(const char *s, const char *p) {
        const char* sBackup = NULL, *pBackup = NULL;
        
        while(*s != '\0'){
            if(*p == '?' || *s == *p){
                s++;
                p++;
            }else if(*p == '*'){
                pBackup = p++;
                if(*p == '\0') return true;  //相当与匹配全部
                sBackup = s; //相当于先匹配 0个，之后可能会逐渐加
                
            }else{
                if(!pBackup) return false;
                p = pBackup;
                s = sBackup;
                s++;
            }
        }
        if(*p == '\0') return true;
        else{
            while(*p != '\0')
                if(*p++ != '*')
                    return false;
            return true;
        }
    }