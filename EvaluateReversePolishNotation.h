int evalRPN(vector<string> &tokens) {
        stack<int> sk;
        for (int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "-") {
                int a = sk.top();
                sk.pop();
                int b = sk.top();
                sk.pop();
                sk.push(getResult(b, a, tokens[i]));
            } else {
                sk.push(atoi(tokens[i].c_str()));
            }
        }
        return sk.top();
    }
    
    int getResult(int a, int b, string c){
        if(c == "*") return a*b;
        else if (c == "/") return a/b;
        else if (c == "+") return a+b;
        else if (c == "-") return a-b;
    }