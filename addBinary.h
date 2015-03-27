string addBinary(string a, string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int len1 = a.length();
    int len2 = b.length();
    int length = max(len1,len2);
    string res="";
    int carry =0,index = 0;
    
    while(index < length){

        int val=0;
        if(index <len1) 
            val += a[index]-'0';
        if(index < len2)
            val += b[index] -'0' ;
            
        val += carry;
        carry = val/2;
        val = val - carry*2;
     
        res.insert(res.begin(),val+'0');
        index++;
    }
    if(carry > 0) res.insert(res.begin(),carry+'0');

    return res;
}
    //solution 2
    string addBinary(string a, string b) {
        int la = a.length(), lb = b.length(), len = max(la,lb);
        int i = la-1, j = lb-1, carry = 0;
        string ret = "";
        while (len-- > 0) {
            int valA = i >= 0 ? a[i--] - '0' : 0;
            int valB = j >= 0 ? b[j--] - '0' : 0;
            int val =  valA + valB + carry;
            carry = val/2;
            val %= 2;
            ret.insert(ret.begin(), val + '0');
        }
        if (carry) ret.insert(ret.begin(), carry + '0');
        return ret;
    }