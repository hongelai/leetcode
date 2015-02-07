    //brute force: time out
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        int result = 0;
        vector<vector<int> > dp(row+1, vector<int>(col+1,0)); //store 0s count
        for (int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] + (matrix[i-1][j-1] - '0' ? 0 : 1);
            }
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                
                for (int x = i; x < row; x++)
                    for (int y = j; y < col; y++) {
                        int zeros = dp[x+1][y+1] - dp[x+1][j+1] - dp[i+1][y+1] + dp[i+1][j+1];
                        if (zeros == 0) result = max(result,(x-i+1)*(y-j+1));
                    }
                
            }
            return result;
    }

    // solution 1: convert into problem "find max rectangle in histogram"
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        int result = 0;
        vector<int> height(col+1,0);
        
        for(int i = 0; i < row; i++){
            stack<int> st;
            for(int j = 0; j < col; j++){//generate a histogram each row
                height[j] = matrix[i][j]  == '1' ? height[j] + 1 : 0;
            }
            for(int k = 0; k <= col;){ //calculate this max rectangel in this histogram
                if(st.empty() || height[k] >= height[st.top()]) st.push(k++);
                else{
                    int tmp = st.top();
                    st.pop();
                    result = max(result,height[tmp]*(st.empty()? k: k-st.top()-1));
                }
            }
        }
        return result;
    }