class Solution {
    public List<String> letterCombinations(String digits) {
        String[] map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> rs = new ArrayList<>();
        if (digits.length() == 0) return rs;
        
        dfs(rs, 0, digits, map, "");
        return rs;
    }
    
    public void dfs(List<String> rs, int index, String digits, String[] map, String item) {
        if (index == digits.length()) {
            rs.add(item);
            return;
        }
        
        String str = map[digits.charAt(index) - '0'];
        for (int i = 0 ; i < str.length(); i++) {
            dfs(rs, index + 1, digits, map, item + str.charAt(i));
        }
    }
    
    //plusOne
    public List<String> letterCombinations1(String digits) {
        String[] map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> rs = new ArrayList<>();
        if (digits.length() == 0) return rs;
        
        rs.add("");
        for (int i = 0; i < digits.length(); i++) {
            int c = digits.charAt(i) - '0';
            
                List<String> tmp = new ArrayList<>();
                for (int j = 0; j < map[c].length(); j++) {
                    for (int k = 0; k < rs.size(); k++) {
                        tmp.add(rs.get(k) + map[c].charAt(j));
                    }
                }
            rs = tmp;
        }
        return rs;
    }
}