class Solution {
    /*
    1, If p.charAt(j) == s.charAt(i) :  dp[i][j] = dp[i-1][j-1];
    2, If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
    3, If p.charAt(j) == '*': here are two sub conditions:
       1 if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
       2 if p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == '.':
            dp[i][j] = dp[i-1][j]   //in this case, a* counts as multiple a 
         or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
         or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty
    */
    public boolean isMatch(String s, String p) {
        if (s == null || p == null) return false;
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        dp[0][0] = true;
        
        //if s is empty, then "x*x*x*" still match
        for (int i = 1; i < p.length(); i++) {
            if (p.charAt(i) == '*' && dp[0][i-1]) {
                dp[0][i+1] = true; //i+1 represent i position at p
            }
        }
        
        for (int i = 0; i < s.length(); i++){
            for (int j = 0; j < p.length(); j++) {
                if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') {
                    dp[i+1][j+1] = dp[i][j];
                }
                
                if (p.charAt(j) == '*') {
                    if (p.charAt(j - 1) != s.charAt(i) && p.charAt(j - 1) != '.') {
                            dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    } else {
                        dp[i+1][j+1] = dp[i+1][j-1] // match empty
                            || dp[i+1][j]   // match single
                            || dp[i][j+1];    // match multiple
                    }
                }
            }
        }
        return dp[s.length()][p.length()];
    }
    
    public boolean isMatch1(String s, String p) {
        if (p.isEmpty()) return s.isEmpty();
        
        if (p.length() == 1) {
            return s.length() == 1 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.');
        }
        
        if (p.charAt(1) != '*') {
            if (s.isEmpty()) return false;
            return (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.') 
                && isMatch(s.substring(1), p.substring(1));
        } else {
            while (!s.isEmpty() 
                   && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.')) {
                if (isMatch(s, p.substring(2))) return true;
                s = s.substring(1);
            }
            // ab ----- c*ab
            return isMatch(s, p.substring(2));
        }
    }
}