class Solution {
    /*
设状态为f[i][j]，表示A[0,i] 和B[0,j] 之间的最小编辑距离。设A[0,i] 的形式是
str1c，B[0,j] 的形式是str2d，
1. 如果c==d，则f[i][j]=f[i-1][j-1]；
2. 如果c!=d，
(a) 如果将c 替换成d，则f[i][j]=f[i-1][j-1]+1；
(b) 如果在c 后面添加一个d，则f[i][j]=f[i][j-1]+1；
(c) 如果将c 删除，则f[i][j]=f[i-1][j]+1；
    */
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        
        int[][] dp = new int[m+1][n+1];
        
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int i = 0; i <= n; i++) dp[0][i] = i;
        
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i-1) == word2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int replace = dp[i-1][j-1];
                    int add = dp[i][j-1];
                    int delete = dp[i-1][j];
                    dp[i][j] = Math.min(replace, Math.min(add, delete)) + 1;
                }
            }
        return dp[m][n];
    }
}