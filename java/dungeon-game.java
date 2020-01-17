class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        if (dungeon.length == 0 || dungeon[0].length == 0) return 0;
        int m = dungeon.length, n = dungeon[0].length;
        int[] dp = new int[n+1];
        
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[n-1] = 1; //不能把dp[n]设为1， 否则后面每列都会影响到
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                dp[j] = Math.max(1, Math.min(dp[j+1], dp[j]) - dungeon[i][j]);
            }
        }
        return dp[0];
    }
}