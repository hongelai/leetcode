int priority(char a) {
    int temp;
    if (a == '^')
        temp = 1;
    else  if (a == '*' || a == '/')
        temp = 2;
    else  if (a == '+' || a == '-')
        temp = 3;
    else temp = 4;
    return temp;
}
//核心思想：栈里面不能存在比当前操作符优先级高的操作符
string infixToPostfix(string infix){

    stack<char> st;

    stringstream output;

    for (unsigned i = 0; i < infix.length(); i++) {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (!st.empty() && priority(st.top()) <= priority(infix[i])) {
                output << st.top();
                st.pop();
            }
            st.push(infix[i]);
        } else if (infix[i] == '(') {
            st.push(infix[i]);
        } else if (infix[i] == ')') {
            while (st.top() != '(') {
                output << st.top();
                st.pop();
            }
            st.pop();
        } else {
            output << infix[i];
        }
    }

    while (!st.empty()) {
        output << st.top();
        st.pop();
    }

    return output.str();
}

// 1 + (1 + 2 * 3 + 3) * 4
//1123*+3+4*+