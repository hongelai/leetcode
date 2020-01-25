class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] sChars = new int[256];
        int[] tChars = new int[256];
        
        if (s.length() != t.length()) return false;
        
        for (int i = 0; i < s.length(); i++) {
                if (sChars[s.charAt(i)] == tChars[t.charAt(i)]) {
                    sChars[s.charAt(i)] = i+1;
                    tChars[t.charAt(i)] = i+1;
                } else return false;
        }
        
        return true;
    }
    
    public boolean isIsomorphic_1(String s, String t) {
        HashMap<Character, Character> sMap = new HashMap<>();
        HashMap<Character, Character> tMap = new HashMap<>();
        
        if (s.length() != t.length()) return false;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (!sMap.containsKey(c)) {
                if (tMap.containsKey(t.charAt(i))) {
                        return false;//this line is necessary for this case: ("ab", "aa")
                    }
                sMap.put(s.charAt(i), t.charAt(i));
                tMap.put(t.charAt(i), s.charAt(i));
            } else {
                if (sMap.get(c) != t.charAt(i)) return false;
            }
        }
        return true;
    }
}
