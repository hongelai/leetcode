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