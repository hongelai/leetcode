    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size < 2) return 0;
        int min_val = prices[0];
        int profit = 0;
        for(int i =0; i < size; i++){
            profit = max(profit, prices[i] - min_val);
            min_val  = min(min_val,prices[i]);
        }
        return profit;
    }