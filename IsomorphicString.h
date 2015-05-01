    bool isIsomorphic(string s, string t) {
        int m[256] = {0}, n[256] = {0}; //分别存储 s[i] 和 t[i] 上一次出现的位置，必须相等
        for(int i= 0; i < s.length(); i++){
            if(m[s[i]] != n[t[i]]) return false;
            else m[s[i]] = n[t[i]] = i+1;
        }
        return true;
    }