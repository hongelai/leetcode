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

    // solution 2: convert into problem "find max rectangle in histogram"
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

    //solution 3
    int maximalRectangle(char matrix[][6], int m, int n) {
    
        int left[n], right[n], height[n];
        fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
        int maxA = 0;
        for(int i=0; i<m; i++) {
            int cur_left=0, cur_right=n; 
            for(int j=0; j<n; j++) { // compute height (can do this from either side)
                if(matrix[i][j]==1) height[j]++; 
                else height[j]=0;
            }
            for(int j=0; j<n; j++) { // left[i] 表示在给定height[i]的情况下，可以向左extend到col left[i]
                if(matrix[i][j]== 1) left[j]=max(left[j],cur_left);
                else {left[j]=0; cur_left=j+1;}
            } 
            for(int j=n-1; j>=0; j--) { // right[i] 表示在给定height[i]的情况下，可以向右extend到col right[i], 当right[i] == n, 意味着为空
                if(matrix[i][j]==1) right[j]=min(right[j],cur_right);
                else {right[j]=n; cur_right=j;}  
                 
            }
            // // compute the area of rectangle (can do this from either side)
            for(int j=0; j<n; j++)
                maxA = max(maxA,(right[j]-left[j])*height[j]);
        }

        return maxA;
    }

    //solution 4
    /*
    h(0, c) = 0
    h(r, c) = 0 if matrix[r][c] == 0
    h(r, c) = h(r-1, c)+1 otherwise

    l(r, 0) = 0

    l(r, c) = c-p if matrix[r-1][c] == 0
    l(r, c) = min(l(r − 1, c), c − p) otherwise

    r(r,C+1) = 0

    r(r,c) = p-c if matrix[r-1][c] == 0
    r(r,c) = min(r(r − 1, c), p − c) otherwise
    */
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> L(n,0);
        vector<int> R(n,0);
        vector<int> height(n,0);
        int maxA = 0;
    
        for(int i = 0; i < m; i++) {
            int zeroL = -1, zeroR = n; 
            for(int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') height[j]++; 
                else height[j] = 0;
            }
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i - 1 >= 0 && matrix[i-1][j] != '0')
                    {
                        L[j] = min(j - zeroL, L[j]);
                    } else {
                        L[j] = j - zeroL;
                    }
                } else {
                    L[j] = 0;
                    zeroL = j;
                }
            }
            for (int j = n - 1; j >= 0; j--){
                if (matrix[i][j] == '1'){
                    if (i - 1 >= 0 && matrix[i-1][j] != '0')
                    {
                        R[j] = min(zeroR - j, R[j]);
                    } else {
                        R[j] = zeroR - j;
                    }
                } else {
                    R[j] = 0;
                    zeroR = j;
                }
            }
            for (int j = 0; j < n; j++) {
                maxA = max(maxA, (R[j] + L[j] - 1) * height[j]);
            }
        }
        return maxA;
    }