    string simplifyPath(string path) {
        stack<string> res;
        string str = "";
        int len = path.length();
        
        for(int i = 0; i < len;){
            int j = i + 1;
            while(path[j] != '/' && j < len) j++;
            string sub = path.substr(i,j-i);
            if(sub == "/.." ){
                if(!res.empty()) res.pop();
            }else if(sub != "/."){
                if(sub != "/" || (sub == "/" && path[j] != '/' && res.empty()))
                    res.push(sub);
            } 
            
            i = j;
        }
        if(res.empty()) res.push("/");
        
        while(!res.empty()){
            str = res.top() + str;
            res.pop();
        } 
        return str;
    }