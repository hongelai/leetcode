void sayNum(int n)
{
    vector<string> big = {"","thousand","million","billion"};
    vector<string> tens ={"","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninty"};
    vector<string> ones = {"","one","two","three","four","five","six","seven","eight","nine"};
    vector<int> num;
    stack<string> s;
    
    for(; n/10 != 0;){
        num.push_back(n%10);
        n /= 10;
    }
    num.push_back(n);
    
    int count = 0;

    for(int i = 0; i < num.size();i+=3){
        string str = "";
        if(i +2 < num.size())
             str += ones[num[i+2]]+" handred ";

        if(i+1 < num.size())
               str += tens[num[i+1]]+" ";

        str += ones[num[i]]+" "+ big[count++]+" ";
        s.push(str);

    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }      
    

}