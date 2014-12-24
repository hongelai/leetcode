    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> item;
        dfs(s,0,item,res);
        return res;
    }
    void dfs(string str, int start, vector<string> &item, vector<vector<string>> & res){
        int length = 1;
        int oriSize = item.size();
        for(int i = start; i < str.length();){
            string sub = str.substr(start,length);
            item.resize(oriSize);
            
            if(isPalidrome(sub)){
                
                item.push_back(sub);
                if(length == str.length()-i)
                {
                    res.push_back(item);
                    break;
                }
                i += length;
                dfs(str,i,item,res);
            } 
            length++;
            i = start;
            if(length > str.length() - i) break;
            
        }  
    }
    void dfs_1(string str, int start, vector<string> &item, vector<vector<string>> & res){

        if(start == str.size()) res.push_back(item);

        for(int i = start; i < str.length(); i++){
            
            string sub = str.substr(start,i - start + 1);
            if(isPalidrome(sub))
            {    
                item.push_back(sub);    
                dfs(str,i+1,item,res);
                item.pop_back();
            } 
        }  
    }
    /*
    //可以先dp計算 palindrome
    vector<vector<bool> > dp(size, vector<bool>(size));
    for (int i = size - 1; i >= 0; --i) { //必须逆序，可以利用 i+1的值
            for (int j = i; j < size; ++j) {
                dp[i][j]=(s[i]==s[j])&&(j<i+2||dp[i+1][j-1]); //Si == Sj, 且 i，j距離小於 2 或者 Si+1 == S j-1 
            }
    }
    */
    bool isPalidrome(string sub){
        int low = 0, high = sub.size()-1;
        while(low < high){
            if(sub[low] == sub[high]){
                low++;
                high--;
            }else break;
        }
        return low >= high;
    }
    