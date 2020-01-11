public class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        //dp[i][j] = (s[i] == s[j]) && (j-i < 2 || d[i+1][j-1])
        
        int start = 0, end = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if ((s.charAt(i) == s.charAt(j)) 
                    && (j-i <= 2 || dp[i+1][j-1] == 1)) {
                    dp[i][j] = 1;
                    if (j - i > end - start) {
                        start = i;
                        end = j;
                    }
                }
            }
        }
        return n == 0 ? "" :s.substring(start, end+1);
    }
}