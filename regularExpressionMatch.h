    bool isMatch(const char *s, const char *p) {
        if(*p =='\0') return *s =='\0';
        
     
        if(*(p+1) == '*'){
            //* 的作用，P能匹配：匹配0个，进入下一阶段子集；匹配1个，进入子集；匹配2个。。。。
            //匹配不上， 直接进入下一阶段匹配
            while((*p == '.' && *s != '\0') || *s == *p){ 
               if(isMatch(s,p+2)) return true;
               s++;
            }
            return isMatch(s,p+2);
            
        }else{
            if((*p == '.' && *s != '\0') || *s == *p) return isMatch(s+1,p+1);
            else return false;
        }
    }