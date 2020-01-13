class Solution {
    
    public boolean wordBreak(String s, List<String> wordDict) {
        int len = s.length();
        HashSet<String> dict = new HashSet<>(wordDict);
        boolean[] dp = new boolean[s.length()+1]; //dp[i]: 0->i can be built from dict
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j]) {
                    String word = s.substring(j, i);
                    if (dict.contains(word)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[len];
    }
    
    public boolean wordBreak_1(String s, List<String> wordDict) {
        HashSet<String> dict = new HashSet<>(wordDict);
        int[] cache = new int[s.length()];//-1, 0 , 1
        Arrays.fill(cache, -1);
        
        return solve(s, 0, dict, cache) == 1;
    }
    
    private int solve(String s, int start, HashSet<String> dict, int[] cache) {
        if (start >= s.length()) return 1;
        if (cache[start] != -1) return cache[start];
        
        for (int i = start + 1; i <= s.length(); i++) {
            String word = s.substring(start, i);
            
            if (dict.contains(word)) {
                if (solve(s, i, dict, cache) == 1) {
                    cache[start] = 1;
                    return 1;
                }
            }
        }
        
        cache[start] = 0;
        return cache[start];
    }
}