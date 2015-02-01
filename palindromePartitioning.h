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
    
    //dynamic solution
    vector<vector<string>> partition(string s) {
        int size = s.length();
        vector<vector<bool> > dp(size,vector<bool>(size,false));
        vector<vector<string> > res[size];
        for(int i = size-1; i >= 0; i--)
            for(int j = i; j < size; j++){
                dp[i][j] = (s[i] == s[j]) && (j - i <= 1 || dp[i+1][j-1]);
            }
            
        for(int i = size-1; i >= 0; i--)
            for(int j = i; j < size; j++){
                if(dp[i][j]){
                    string sub = s.substr(i,j-i+1);
                    if(j == size-1){
                        res[i].push_back(vector<string>(1,sub));
                    }else{
                        
                        for(int k = 0; k < res[j+1].size(); k++){//res[i]可能非空，要修改好一条记录再push进去
                            vector<string> tmp = res[j+1][k];
                            tmp.insert(tmp.begin(),sub);
                            res[i].push_back(tmp);
                        }
                        // for (auto iter : res[j+1]) {
                        //     iter.insert(iter.begin(), sub);
                        //     res[i].push_back(iter);
                        // }
                    }
                }
            }
        return res[0];
    }
/*
for(int j = 0; j <= i; j++) {
    if([i, j]为回文) {
        for(list l : lists[j]) {
            newl = clone(l) // 做一份原来list的copy
            newl.add(s[j, i]); //将j到i的这部分字符串加入到新串中。
            list[i].add(newl); //这时候newl对应着一个划分，将它加入到i所在的划分集合中。
        }
    }
}
每一个res[i] 代表 从i到字符串末端 所有回文划分集合
1.dp找出所有回文子串
2.计算res[i]
a.从i开始找回文子串dp[i][j]
b.把res[j+1]复制一份，然后对于res[j+1]里面的每一种划分方法前面加上子串sub(i,j)
c.就获得了在res[j+1]基础上的划分方法集合
d.最后要是dp[i][size-1] 也是回文的话，把他加到集合里面
*/