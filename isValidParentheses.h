    bool isValid(string s) {
        stack<char> sk;
        for(auto it=s.begin(); it != s.end();it++){
            if(*it == '(' || *it == '{' || *it == '[' )
                sk.push(*it);
            else if(*it == ')' || *it == '}' || *it == ']' ){
                if(!sk.empty()){
                    if((*it == ')' && sk.top() == '(')||(*it == ']' && sk.top() == '[')||(*it == '}' && sk.top() == '{'))
                        sk.pop();
                }
                else return false;
            }
        }
        if(sk.empty()) return true;
        else return false;
    }