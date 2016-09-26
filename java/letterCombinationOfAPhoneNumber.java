public class Solution {
    public List<String> letterCombinations1(String digits) {
        ArrayList<String> ret = new ArrayList<String>();
        if (digits.isEmpty()) return ret;
        String[] keyboard = new String[]{" ","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        String s = "";
        dfs(ret, keyboard, digits, s);
        return ret;
    }
    
    public void dfs(ArrayList<String> ret, String[] keyboard, String digits, String s) {
        if (s.length() == digits.length()) {
            ret.add(s);
            return;
        }
        
        String letters = keyboard[digits.charAt(s.length())-'0'];
        for (int i = 0; i < letters.length(); i++) {
            dfs(ret, keyboard, digits, s+letters.charAt(i));
        }
    }
    
    
    //plus one
    public List<String> letterCombinations(String digits) {
        ArrayList<String> ret = new ArrayList<String>();
        if (digits.isEmpty()) return ret;
        String[] keyboard = new String[]{" ","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ret.add("");
        
        for (int i = 0; i < digits.length(); i++) {
            ArrayList<String> tmp = new ArrayList<String>();
            String letters = keyboard[digits.charAt(i)-'0'];
            for (int j = 0; j < letters.length(); j++) {
                
                for (int k = 0; k < ret.size(); k++) {
                    tmp.add(ret.get(k) + letters.charAt(j));
                }
            }
            ret = tmp;
        }
        return ret;
    }
}