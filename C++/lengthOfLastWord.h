    int lengthOfLastWord(const char *s) {
        char str[strlen(s)];
        strcpy(str,s);
        reverse(str,str+strlen(str));
        stringstream is(str);
        string res;
        is>>res;
        reverse(res.begin(),res.end());//can delete, because we only need the length,donot care the result string 
        return res.size();
    }
    int lengthOfLastWord(const char *s) {
        int res = 0;
        int length = strlen(s);
        for (int i = length - 1; i >= 0; --i)
            if (s[i] != ' ') res++;
            else if(res > 0) break;
        return res;
    }