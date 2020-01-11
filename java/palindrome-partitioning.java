class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>>[] res = new ArrayList[s.length()+1];
        List<List<String>> rs = new ArrayList<List<String>>();
        int len = s.length();
        
        if (len == 0) return rs;
        
        boolean[][] dp = new boolean[len][len];
        res[0] = new ArrayList<List<String>>();
        res[0].add(new ArrayList<String>());
        
        for (int j = 0; j < len; j++) {
            res[j+1] = new ArrayList<List<String>>();
            for (int i = j; i >= 0; i--) {
                if ((j - i <= 2 || dp[i+1][j-1]) && s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = true;

                    // solution 1 : res[i] - all palins results end at i
                    String str = s.substring(i, j+1);
                    for (List<String> a : res[i]) {
                        List<String> ri = new ArrayList<String>(a);
                        ri.add(str);
                        res[j+1].add(ri);
                    }
                }
            }
        }
        
        // solution 2
        // dfs(rs, new ArrayList<String>(), dp, 0, s);
        
        return res[len];
    }
    
    private void dfs(List<List<String>> rs, ArrayList<String> item, boolean[][] dp, int start, String s) {
        if (start == s.length()) {
            rs.add(new ArrayList<String>(item));
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (dp[start][i]) {
                item.add(s.substring(start, i+1));
                dfs(rs, item, dp, i+1, s);
                item.remove(item.size()-1);
            }
        }
    }
}