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
}