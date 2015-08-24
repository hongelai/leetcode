    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size < 2) return 0;
        vector<int> left(size,0),right(size,0);
        
        for(int i =1, valley = prices[0]; i < size; i++){
            valley = min(valley, prices[i]);
            left[i] = max(left[i-1], prices[i] - valley);
        }
        for(int i = size-2, peak = prices[size-1]; i >=0; i--){
            peak = max(peak, prices[i]);
            right[i] = max(right[i+1], peak - prices[i]);
        }
        
        int profit = 0;
        for(int i =0; i < size; i++){
            profit = max(profit,left[i]+ right[i]);
        }
        return profit;
    }