class Solution {
    public String reverseWords(String s) {
        Stack<Character> st = new Stack<>();
        StringBuilder rs = new StringBuilder();
        s = reverse(s.trim());
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c != ' ') {
                st.push(c);
            } else {
                while(!st.isEmpty()) {
                    rs.append(st.pop());
                }
                if (rs.charAt(rs.length()-1) != ' ') rs.append(c);
            }
        }
        
        while(!st.isEmpty()) {
            rs.append(st.pop());
        }
        
        return rs.toString();
    }
    
    private String reverse(String s) {
        StringBuilder rs = new StringBuilder();
        
        for (int i = s.length()-1; i >= 0; i--) {
            rs.append(s.charAt(i));
        }
        
        return rs.toString();
    }
}