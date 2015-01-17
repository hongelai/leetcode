    string multiply(string num1, string num2) {
        int carry = 0, len1 = num1.length(), len2 = num2.length();
        vector<int> res(len1+len2,0);
        string str;
        
        for(int i = len1-1; i >=0; i--){
            for(int j = len2-1; j >=0; j--){
                int index = len1-1 + len2-1 - i - j; //from 0...N,
                int val = (num1[i]-'0')*(num2[j]-'0') + res[index];
                carry = val / 10;
                res[index] = val % 10;
                res[index+1] = res[index+1] + carry;
            }
        }
        //reverse result array and convert to str
        int pos = len1 + len2 - 1;
        for(; pos >0; pos--) if(res[pos] != 0) break; //cannot be pos>=0 because of case 0 X 0
        for(int i = pos; i >=0; i--) str.insert(str.end(), res[i] + '0');
        return str;
    }

    //use vector<string>, and erase the 0's
        string multiply(string num1, string num2) {
        int N = num1.size(), M = num2.size();
        string res(N+M, '0');
        for (int i = N - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = M - 1; j >= 0; --j)
            {
                int sum = carry + (res[i+j+1] - '0') + 
                          (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] = sum % 10 + '0';
                carry = sum / 10;
            }
            res[i] += carry;
        }
        while (res.size() > 1 && res[0] == '0')
            res.erase(res.begin());
        return res;
    }