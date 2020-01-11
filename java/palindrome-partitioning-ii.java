class Solution {
    public int minCut(String s) {
        int len = s.length();
        if (len == 0) return 0;
        
        boolean[][] dp = new boolean[len][len];
        int[] p = new int[len]; //p[i]表示子串 [0, i] 范围内的最小分割数
        for (int j = 0; j < len; j++){
            p[j] = j; // worst case ：每个字符都分割
            for (int i = 0; i <= j; i++) {
                if ((j - i <= 2 || dp[i+1][j-1]) && s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = true;
                    p[j] = i == 0 ? 0 : Math.min(p[j], p[i-1] + 1);
                }
            }
        }
        return p[len - 1];
    }
}