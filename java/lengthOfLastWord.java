public class Solution {
    public int lengthOfLastWord(String s) {
        int len = 0;
        if (s.length() == 0) return 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if(s.charAt(i) != ' ') len++;
            else if(len > 0) break; //trim space at the end
        }
        
        return len;
    }
}