    int maxProfit(int k, vector<int> &prices) {
        int size = prices.size();
        int res = 0;
        if (k >= size/2) {  //same as unlimitted transaction
             for (int i = 1; i < size; i++) {
                 if (prices[i] > prices[i-1]) res += prices[i] - prices[i-1];
             }
             return res;
        }
        
        vector<vector<int> > dp(k+1, vector<int>(size)); //max profit for the previous j node with at most k transaction
        for (int i = 1; i <= k; i++){
            int tmpMax = 0 - prices[0];
            for(int j = 1; j < size; j++) { //已经对前j-1个点进行了i-1次交易，从j开始计算profit最大的一次交易（这一个for loop只需要进行一次交易即可）
                dp[i][j] = max(dp[i][j-1], tmpMax + prices[j]);//保持之前的 或者 之前的第i次交易不算，在j卖出，作为第i次交易
                tmpMax = max(tmpMax, dp[i-1][j-1] - prices[j]); //计算在前i-1个点进行j-1次交易还要买进第x个点（x是之前某一个点或j点）的股票所剩下的钱的最大值
            }
        }
        return dp[k][size-1];
    }

    /*
    idea:
    1.每一个迭代的第一个点都是只能买进，所以tmpMax是-prices[0]
    2.对于每一个i的迭代，都是意味着前面已经进行了i-1次交易，本次迭代只需要进行1次交易
    3.买进是亏prices[j],卖出是赚prices[j]
    4.tmpMax记录的是本轮迭代到目前为止，买了进一个点并且只进行i-1次交易能剩下的钱的最大值
    */