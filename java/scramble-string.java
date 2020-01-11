class Solution {
    public boolean isScramble(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        
        if (m != n) return false;
        if (s1.equals(s2)) return true;
        
        if (!hasSameLetters(s1, s2)) return false;
        
        for (int i = 1; i < m; i++) {
            String s1_1 = s1.substring(0, i);
            String s1_2 = s1.substring(i, m);
            String s2_1 = s2.substring(0, i);
            String s2_2 = s2.substring(i, m);
            if (isScramble(s1_1, s2_1) && isScramble(s1_2, s2_2)) return true;
            s2_1 = s2.substring(0, s2.length() - i);
            s2_2 = s2.substring(s2.length() - i);
            if (isScramble(s1_1, s2_2) && isScramble(s1_2, s2_1)) return true;
        }
        return false;
    }
    
    private boolean hasSameLetters(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        
        int[] count = new int[256];
        
        for (int i = 0; i < s1.length(); i++) {
            count[s1.charAt(i)]++;
            count[s2.charAt(i)]--;
        }
        
        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) return false;
        }
        
        return true;
    }
}