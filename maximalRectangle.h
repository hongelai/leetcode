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