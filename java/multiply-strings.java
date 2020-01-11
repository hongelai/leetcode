class Solution {
    public String multiply(String num1, String num2) {
        StringBuilder rs = new StringBuilder();
        int[] ret = new int[num1.length() + num2.length()];
        
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0 ; j--) {
                int sum = (num1.charAt(i) - '0') * (num2.charAt(j) - '0') + ret[i+j+1];
                ret[i+j] += sum/10;
                ret[i+j+1] = sum%10;
            }
        }
        
        for (int i = 0; i <  ret.length; i++) {
            if (!(rs.length() == 0 && ret[i] == 0)) rs.append((char)(ret[i]+'0'));
        }
        return rs.length() == 0 ? "0" : rs.toString();
    }
}