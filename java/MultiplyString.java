public class Solution {
    public String multiply(String num1, String num2) {
        int l1 = num1.length(), l2 = num2.length();
            int[] ret = new int[l1+l2];
            for (int i = l1 - 1; i >= 0; i--) {
                for (int j = l2 -1; j >= 0; j--) {
                    int sum = (num1.charAt(i) - '0') * (num2.charAt(j) - '0') + ret[i+j+1];
                    int val = sum % 10;
                    ret[i+j+1] = val;
                    ret[i+j] += sum / 10;
                }
            }
            StringBuilder result = new StringBuilder();
            for (int k : ret) {
                if (!(result.length() == 0 && k ==0)) result.append(k);
            }
            return result.length() == 0 ? "0" : result.toString();
    }
}