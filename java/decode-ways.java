class Solution {
    public int numDecodings(String s) {
        if (s == null || s.length() == 0 || s.charAt(0) == '0') return 0;
       
        int[] dp = new int[s.length()+1];
        
        dp[0] = dp[1] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == '0') {
                if (s.charAt(i-1) != '1' && s.charAt(i-1) != '2') {
                    return 0;
                } else {
                    dp[i+1] = dp[i-1];
                }
            } else {
                int total = (s.charAt(i-1) - '0') * 10 + s.charAt(i) - '0';
                if (total > 10 && total <= 26) {
                    dp[i+1] = dp[i] + dp[i-1];
                } else {
                    dp[i+1] = dp[i];
                }
            }
            
        }
        return dp[s.length()];
    }
}