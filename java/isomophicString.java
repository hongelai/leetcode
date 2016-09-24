public class Solution {
    public boolean isIsomorphic(String s, String t) {
        //match same pattern
        if (s.length() != t.length()) return false;
        int[] m = new int[256], n = new int[256]; //last occurrence in the string
        Arrays.fill(m, 0);
        Arrays.fill(n, 0);
        for (int i = 0; i < s.length(); i++) {
            if (m[s.charAt(i)] != n[t.charAt(i)]) return false;
            else {
                m[s.charAt(i)] = n[t.charAt(i)] = i + 1; // set to i + 1 to avoid collide with init val
            }
        }
        return true;
    }
}