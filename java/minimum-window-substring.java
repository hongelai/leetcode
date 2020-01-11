class Solution {
    public String minWindow(String s, String t) {
        int[] dict = new int[256];
        
        for (int i = 0; i < t.length(); i++) {
            dict[t.charAt(i)]++;
        }
        
        int left = 0, count = 0, minLen = Integer.MAX_VALUE;
        int m = s.length(), n = t.length();
        String rs = "";
        
        //相当于把t叠加到s， 只有存在于t中的字符才有可能在dict中大于0
        for (int i = 0; i < m; i++) {
            if (--dict[s.charAt(i)] >= 0) {
                count++;
            }
            
            while (count == n) {
                if (minLen > i-left+1) {
                    minLen = i-left+1;
                    rs = s.substring(left, i+1);
                }
                if (++dict[s.charAt(left)] > 0)  count--;
                left++;
            }
        }
        return rs;
    }
}