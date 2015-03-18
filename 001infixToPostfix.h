int priority(char a) {
    int temp;
    if (a == '^')
        temp = 1;
    else  if (a == '*' || a == '/')
        temp = 2;
    else  if (a == '+' || a == '-')
        temp = 3;
    return temp;
}
//核心思想：栈里面不能存在比当前操作符优先级高的操作符
string infixToPostfix(string infix){

    stack<char> operator_stack;

    stringstream output;

    for (unsigned i = 0; i < infix.length(); i++) {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (!operator_stack.empty() && priority(operator_stack.top()) <= priority(infix[i])) {
                output << operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push(infix[i]);
        } else if (infix[i] == '(') {
            operator_stack.push(infix[i]);
        } else if (infix[i] == ')') {
            while (operator_stack.top() != '(') {
                output << operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.pop();
        } else {
            output << infix[i];
        }
    }

    while (!operator_stack.empty()) {
        output << operator_stack.top();
        operator_stack.pop();
    }

    return output.str();
}

// 1 + (1 + 2 * 3 + 3) * 4
//1123*+3+4*+