    int longestValidParentheses(string s) {
        int len = s.length(), lastIndex = -1, ret = 0;
        stack<int> st;
        
        for (int i = 0; i < len; i++) {
            if (s[i] == '('){
                st.push(i);
            } else {
                if (st.empty()) {
                    lastIndex = i;
                } else {
                    st.pop();
                    if (!st.empty()) ret = max(ret, i - st.top());
                    else ret = max(ret, i - lastIndex);
                }
            }
        }
        return ret;
    }