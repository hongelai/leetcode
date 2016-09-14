public class Solution {
    public int[] plusOne(int[] digits) {
        
        int carry = 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            int total = digits[i] + carry;
            int val = total%10;
            carry = total/10;
            digits[i] =  val;
        }
        if (carry == 0) return digits;
        
        int[] rs = new int[digits.length + 1];
        System.arraycopy(digits, 0, rs, 1, digits.length);
        rs[0] = carry;
        
        return rs;
    }
}