//http://blog.csdn.net/beiyeqingteng/article/details/7044471
//grayCode --> binary Bi = Gi XOR Bi+1
//binary-->graycode  Gi = Bi XOR Bi+1
    vector<int> grayCode(int n) {
        vector<int> res(1<<n);
        for(int i = 0; i < 1<<n; i++)
            res[i] = (i >> 1) ^ i; //GrayCode(n) = B(n) XOR B(n+1). B(n)表示n的二进制，B(n+1)表示n右移一位的二进制

        return res;
    }
    
    //solution2 : n= 2 00 01 11 10
    //n = 3  000 001 011 010 110 111 101 100
    //前面4个只是在n = 2 的基础上加前面0 对结果没影响 后四个是逆序后前面加1
    vector<int> grayCode(int n) {
        vector<int> result;      
        result.push_back(0);
        
        for (int i = 0; i < n; i++) {
            int sz = result.size();
            for (int j = sz - 1; j >= 0; j--){
                int tmp = result[j] + (1<<i);
                result.push_back(tmp);
            }
        }
        return result;
    }

//recursive method
        vector<int> grayCode(int n) {
        vector<int> res;
        if(n == 0){
            res.push_back(0);
            return res;
        } 
        vector<string> str = grayCodeRe(n);
        for(int i = 0; i < pow(2,n); i++) res.push_back(binary2Int(str[i]));
        return res;
    }
    vector<string> grayCodeRe(int n){
        vector<string> str(pow(2,n),"");
        if(n == 1){ 
            str[0] += '0';
            str[1] += '1';
            
            return str;
        }
        vector<string> grayCode = grayCodeRe(n-1);
        for(int i = 0, j = str.size()-1; i < j; i++,j--){
          
            str[i] = '0' + grayCode[i];
            str[j] = '1' + grayCode[i];
        }
        return str;
    }
    int binary2Int(string str){
        // return stoi(str,nullptr,2); //use stl
        int res = 0, length = str.length();
        for(int i = length-1; i >= 0; i--){
            res += (str[i]-'0')*pow(2,length - i - 1);
        }
        return res;
    }
