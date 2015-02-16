    //保证最小的都有一颗， 从左到右扫一遍获取上升区间所需糖果，从右往左扫获取下降区间所需糖果
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        int sum = 0;
        int inc = 1;
        vector<int> increment(size, 1);
        
        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i-1]) {
                increment[i] = ++inc;
            } else {
                inc = 1;   
            }       
        }
        for (int i = size - 2, inc = 1; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                increment[i] = max(++inc, increment[i]);
            } else {
                inc = 1;
            }
        }
        for (int i = 0; i < size; i++ ) sum += increment[i];
        return sum;
    }