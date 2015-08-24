    string largestNumber(vector<int> &num) {
        string res;
        vector<string> str;
        int size = num.size();
        auto func = [=](string a, string b){
            return a+b > b+a;
        };
        
        int index = 0;
        for(auto it  = num.begin(); it != num.end(); it++){
            str.push_back(to_string(*it));
        }
        sort(str.begin(),str.end(),func);
        for(auto it  = str.begin(); it != str.end(); it++){
            res += *it;
        }
        //remove the 0's at the beginning 
        index = 0;
        while(res[index] == '0' && index+1 < res.size()) index++;
        return res.substr(index);
    }