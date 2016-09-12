public class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        
        for (int i = 0; i < s.length(); i ++) {
            if(s.charAt(i) == ')' || s.charAt(i) == '}' || s.charAt(i) == ']') {
                if(!st.empty()){
                    if ((s.charAt(i) == ')' && st.peek() == '(') 
                        || (s.charAt(i) == ']' && st.peek() == '[')
                        || (s.charAt(i) == '}' && st.peek() == '{')){
                        st.pop();
                    } else {
                        return false;
                    }
                } else return false;
            } else {
                st.push(s.charAt(i));
            }
        }
        return st.empty();
    }
}