    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        
        dfs(s,0,0,ip,result);
        
        return result;
    }
    void dfs(string &s,int step, int start, string& ip, vector<string> &res){
        if(step == 4 && start == s.size())  res.push_back(ip);
        if(step == 4) return;
        
        int oriSize = ip.size();
        if(oriSize != 0) ip.push_back('.');
        int num = 0;
        for(int i = start; i < s.size(); i++){
            num  = num*10 + s[i] - '0';
            if(num > 255) break;
            ip.push_back(s[i]);
            dfs(s,step+1,i+1,ip,res);
            if(num == 0) break; //not allow prefix '0', allow single '0'
        }
        ip.resize(oriSize);
    }