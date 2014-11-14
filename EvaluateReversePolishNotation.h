class Solution {
public:
    int calculate(int a, int b, string op){
        if(op == "+")
            return a+b;
        else if(op == "-")
            return a-b;
        else if(op =="*")
            return a*b;
        else if(op == "/")
            return a/b;
        else 
            return 0;
    }
    int evalRPN(vector<string> &tokens) {
        stack<int> sk;
        vector<string>::const_iterator it = tokens.begin();
        for(;it != tokens.end();it++){
            if(*it != "+" && *it != "-" && *it != "*" && *it != "/" ){
                sk.push(atoi((*it).c_str()));
            }else{
                int a = sk.top();
                sk.pop();
                int b = sk.top();
                sk.pop();
                int result = calculate(b,a,*it);
                sk.push(result);
            }
        }
        return sk.top();
    }
};