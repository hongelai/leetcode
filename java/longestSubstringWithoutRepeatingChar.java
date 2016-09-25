public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] dict = new int[256]; 
       Arrays.fill(dict, -1);
       int max = 0, start = 0, end = 0;
       
       while (end < s.length()) {
           while (end < s.length() && dict[s.charAt(end)] == -1) {
               dict[s.charAt(end)] = end;
               end++;
           }
           if (end == s.length()) {
               max = Math.max(max, end - start);
           } else {
               //shrink the window
               max = Math.max(max, end - start);
               int pos = dict[s.charAt(end)];
               while (start <= pos) {
                   dict[s.charAt(start++)] = -1;
               }
           }
           
       }
       return max;
    }
}