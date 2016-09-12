public class Solution {
    public boolean isPalindrome1(int x) {
        if (x < 0) return false;
        int l = 1;
        while(x/l >= 10) {
            l *= 10;
        }
        while (x > 0) {
            int low = x % 10;
            int high = x / l;
            if (low != high) return false;
            x = x % l;
            x /= 10;
            l /= 100;
        }
        return true;
    }
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        return x == reverse(x);
    }
    public int reverse(int x) {
        int rs = 0;
        while(x > 0) {
            rs = x%10 + rs*10;
            x /= 10;
        }
        return rs;
    }
}