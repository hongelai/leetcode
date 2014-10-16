    int longestValidParentheses(string s) {
        
        if(s.size() == 0) return 0;
        stack<int> st;
        auto pos = s.begin();
        int result = 0;
        int last  = -1; // last pos of ')'
        while(*pos){
            if(*pos == '('){
                st.push(distance(s.begin(),pos));
            }else{
                if(!st.empty()){
                    st.pop();
                    if(!st.empty())
                        result = max(result,distance(s.begin(),pos) - st.top());
                    else
                        result = max(result,distance(s.begin(),pos)-last);
                }else{
                    last = distance(s.begin(),pos);
                }
                
            }
            pos++;
        }

        return result;
    }