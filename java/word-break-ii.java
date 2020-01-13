class Solution {
    // O(n^2) 因为每个substring 只需要计算一次，每次一个for loop. Space O(n)
    public List<String> wordBreak_1(String s, List<String> wordDict) {
        HashSet<String> dict = new HashSet<>(wordDict);
        HashMap<String, List<String>> map = new HashMap<>();
        
        return solve(map, dict, s);
    }
    
    private List<String> solve(HashMap<String, List<String>> map, HashSet<String> dict, String s) {
        if (map.get(s) != null) return map.get(s);
        
        List<String> res = new ArrayList<>();
        if (s == null || s.isEmpty()) {
            res.add("");
            return res;
        }
        
        for (int i = 0; i <= s.length(); i++) {
            String word = s.substring(0, i);
            
            if (dict.contains(word)) {
                List<String> items = solve(map, dict, s.substring(i));
                
                for (String item : items) {
                    res.add(word+ (item.isEmpty() ? "" : " ") + item);
                }
            }
        }
        map.put(s, res);
        
        return res;
    }
    
    // memory limit exceed
    public List<String> wordBreak(String s, List<String> wordDict) {
        int len = s.length();
        HashMap<String, List<String>> map = new HashMap<>();
        boolean[] dp = new boolean[len+1];
        HashSet<String> dict = new HashSet<>(wordDict);
        
        dp[0] = true;
        map.put("", Arrays.asList(""));
        
        for (int i = 1; i <= len; i++) {
            List<String> newList = new ArrayList<>();
            
            for (int j = 0; j < i; j++) {
                if (dp[j]) { //dp[j] + sub(j, i)
                    String word = s.substring(j, i);
                    
                    if (dict.contains(word)) {
                        dp[i] = true;
                        String sub = s.substring(0, j);
                        for (String item : map.getOrDefault(sub, new ArrayList<>())) {
                            newList.add(item + (item.isEmpty() ? "": " ") + word);
                        }
                    }
                }
            }
            if (!newList.isEmpty())map.put(s.substring(0, i), newList);
        }
        
        return map.get(s) == null ? new ArrayList<>() : map.get(s);
    }
}