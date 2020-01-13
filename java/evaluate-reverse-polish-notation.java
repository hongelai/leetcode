class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        
        for (String token : tokens) {
            if (!token.equals("+") && !token.equals("-")  && !token.equals("*")  && !token.equals("/" )) {
                st.push(Integer.valueOf(token));
            } else {
                int second = st.pop();
                int first = st.pop();
                int rs = 0;
                if (token.equals("+")) {
                    rs = first + second;
                } else if (token.equals("-")) {
                    rs = first - second;
                } else if (token.equals("*")) {
                    rs = first * second;
                } else {
                    rs = first / second;
                }
                st.push(rs);
            }
        }
        return st.peek();
    }
}