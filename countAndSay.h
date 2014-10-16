    string countAndSay(int n) {
        string result = "1";
        while(--n){
            result = getNext(result);
        }
        return result;
    }
    string getNext(string res){
        ostringstream os;
        for(auto i = res.begin(); i < res.end();){
            auto j = find_if(i,res.end(),bind1st(not_equal_to<char>(),*i));
            os<<distance(i,j)<<*i;
            i = j;
        }
        return os.str();
    }
    string countAndSay(int n){
        string res = "1";

        for(int i = 2; i <= n; i++){
            stringstream ss;
            int N  = res.size();
            int j =0;
            while(j < N){
                int k=j+1;
                while(k < N && res[j] == res[k]) k++;
                ss<<k-j<<res[j];
                j = k;
            }
            ss>>res;
        }
        return res;
    }