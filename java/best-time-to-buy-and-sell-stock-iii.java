class Solution {
    /* 1. 买进卖出算一次交易，买进算亏钱，卖出算赚钱
     * 2. dp[i][j] - 前j天最多进行i次交易的最大利润
     * 3. tmpMax - 进行了i-1次交易，并在在某一天买进了股票，剩下的钱最大值
     */
    public int maxProfit(int[] prices) {
        int size = prices.length;
        if(size == 0) return 0;
        
        int[][] dp = new int[3][size];
        for (int i = 1; i <= 2; i++) {
            int tmpMax = -prices[0];
            for (int j = 1; j < size; j++) {
                dp[i][j] = Math.max(dp[i][j-1], tmpMax + prices[j]);
                tmpMax = Math.max(tmpMax, dp[i-1][j-1] - prices[j]); 
            }
        }
        
        return dp[2][size-1];
    }
}