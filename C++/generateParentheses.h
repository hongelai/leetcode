    vector<string> generateParenthesis(int n) {
        string entry = "";
        vector<string> res;
        dfs(res,entry,0,0,n);
        return res;
    }
    void dfs(vector<string> &res, string &entry, int left, int right, int n){
        
        if(left > n || left < right) return;
        if(left == n && right == n){
            res.push_back(entry);
            return;
        } 
        
        if(left < n){
            entry +="(";
            dfs(res,entry,left+1,right,n);
            entry.pop_back();
        } 
        
        if(right < n){ 
            entry += ")";
            dfs(res,entry,left,right+1,n);
            entry.pop_back();
        }
    }


    //better idea
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisRe(res, n, n, "");
        return res;
    }

    void generateParenthesisRe(vector<string> &res, int left, int right, string s) {
        if (left == 0 && right == 0)
            res.push_back(s);
        if (left > 0)
            generateParenthesisRe(left - 1, right, s + "(");
        if (right > left)
            generateParenthesisRe(left, right - 1, s + ")");
    }