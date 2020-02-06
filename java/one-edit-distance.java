class Solution {
    public boolean isOneEditDistance(String s, String t) {
        if (s.length() < t.length()) return isOneEditDistance(t, s);
        
        for (int i = 0; i < t.length(); i++) {
            if (s.charAt(i) != t.charAt(i)) {
                if (s.length() == t.length()) return s.substring(i+1).equals( t.substring(i+1));//replace
                else return s.substring(i+1).equals(t.substring(i)); //delete
            }
        }
        
        return s.length() - t.length() == 1; //insert
    }
}