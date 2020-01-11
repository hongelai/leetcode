public class Solution {
    public int myAtoi(String str) {
        if (str.length() == 0 || str == null) return 0;
        str = str.trim();
        boolean postive = true;
        int i = 0 , rs =0, n = str.length();
        if (str.charAt(i) == '-' || str.charAt(i) == '+') {
            if (str.charAt(i) == '-') postive = false;
            i++;
        }
        while(i < n && Character.isDigit(str.charAt(i))) {
            if (rs > Integer.MAX_VALUE/10 || (rs == Integer.MAX_VALUE/10 && str.charAt(i) - '0' > Integer.MAX_VALUE%10)) {
                return postive ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            rs = rs * 10 + str.charAt(i++) - '0';
        }
        
        return postive ? rs : rs * -1;
    }

        public int myAtoi(String str) {
        if (str.length() == 0) return 0;
        
        boolean positive = true;
        int index = 0, n = str.length();
        
        // remove heading space
        while (index < n && str.charAt(index) == ' ') index++;
        
        // handle operator
        if (index < n && str.charAt(index) == '-') {
            positive = false;
            index ++;
        }
        else if (index < n && str.charAt(index) == '+') index ++;
        
        long res = 0;
        
        while (index < str.length()) {
            char c = str.charAt(index);
            if (Character.isDigit(c)) {
                res = res*10 + c - '0';
                index++;
            } else {
                break;
            }
            
            if (res > Integer.MAX_VALUE) break;
        }
        if (res > Integer.MAX_VALUE) return positive ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        
        return positive ? (int) res : (int)res * -1;
        
    }
}