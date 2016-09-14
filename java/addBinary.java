public class Solution {
    public String addBinary(String a, String b) {
        StringBuilder rs = new StringBuilder();
        
        int carry = 0, i = a.length()-1, j = b.length()-1;
        while (i >= 0 || j >= 0) {
            int sum = 0 ;
            if (i >= 0) sum += a.charAt(i--) - '0';
            if (j >= 0) sum += b.charAt(j--) - '0';
            sum += carry;
            rs.append(sum%2);
            carry = sum/2;
        }
        if (carry != 0) rs.append(String.valueOf(carry));
        return rs.reverse().toString();
    }
}