public class Solution {
    public String longestPalindrome(String s) {
        int len  = s.length();
        boolean[][] dp = new boolean[len][len];
        
        //dp[i][j] : substr(i,j) is palindromic
        /*dp[i][j] = (s[i] == s[j]) && (j-i <= 2 || dp[i+1][j-1]). 
        dp[i][j] rely on dp[i+1][j-1], so i need to decrease and j should increase
        */
        for (int i = 0; i < len; i++) {
            Arrays.fill(dp[i],false);
        }
        
        int start = 0, end = 0;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) { // j start from i since we want substr(i, j);
                dp[i][j] = (s.charAt(i) == s.charAt(j)) && (j-i <= 2 || dp[i+1][j-1]);
                if (dp[i][j] && j-i > end - start) {
                    start = i;
                    end = j;
                }
            }
        }
        return s.substring(start, end+1);
    }
}