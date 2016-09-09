public class Solution {
    public int reverse(int x) {
        long ret = 0;
        while(x != 0) {
            ret = x % 10 + ret * 10;
            x /= 10;
        }
        return ret > Integer.MAX_VALUE || ret < Integer.MIN_VALUE ? 0 : (int)ret;
    }
}