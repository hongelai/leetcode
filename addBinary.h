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