    void rotate(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        //副对角线拷贝
        for(int i =0; i < row;i++)
            for(int j = 0; j < row - i; j++){
                swap(matrix[i][j],matrix[row-j-1][col - i  -1]);
            }
        //对折拷贝
        for(int i =0; i < row/2;i++)
            for(int j = 0; j < col; j++){
                swap(matrix[i][j],matrix[row -i-1][j]);
            }
    }

    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n/2; i++) { //layer
            int first = i;
            int last = n - 1 - i;
            for(int j = first; j < last; j++){
                int off = j - first;
                int tmp = matrix[first][j];
                matrix[first][j] = matrix[last-off][first];
                matrix[last-off][first] = matrix[last][last-off];
                matrix[last][last-off] = matrix[first+off][last];
                matrix[first+off][last] = tmp;
            }
        }
    }