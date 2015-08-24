    void reverseWords(string &s) {
        int len = s.length();
        vector<string> res;
        int start = 0, end = 0;
        while(end < len){
            start = end;
            while(end < len && s[end] != ' ' && s[end] != '\0') end++;
            string str = s.substr(start, end-start);
            if(str != "") res.push_back(str);
            end++;
        }
        s = "";
        for(int i = res.size()-1; i >= 0; i--){
            s += res[i]+" ";
        }
        if(s[s.length()-1] == ' ')s.pop_back();
    }


    void reverseWords(string &s) 
    {
        stringstream scin(s);
        string word, res;
        while (scin >> word)
        {
            if (res.length() != 0)
                word += " ";
            res = word + res;
        }
        s = res;
    }