    vector<string> letterCombinations(string digits) {
        vector<string> dic = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string item;
        vector<int> digit;
        
        for(int i = 0; i < digits.length(); i++){
            digit.push_back(digits[i]-'0');
        }
        dfs(dic,0,digit,item,res);
        return res;
    }
    void dfs(vector<string> dic, int index, vector<int> digit, string &item, vector<string>&res){
        if(index == digit.size()){
            res.push_back(item);
            return;
        } 
        int oriSize = item.length();
        for(int i = 0; i < dic[digit[index]].length(); i++){
            item.push_back(dic[digit[index]][i]);
            dfs(dic,index+1,digit,item,res);
            item.resize(oriSize);
        }
    
    }