    void setZeroes(vector<vector<int> > &matrix) {
        //use first row and col as auxillary space, avoid set first row or col 0 before finish
        bool setFirstRow = false, setFirstCol = false;
        int row = matrix.size(), col = matrix[0].size();
        
        for(int i = 0; i < row; i++)
            if(matrix[i][0] == 0) setFirstCol = true;
        
        for(int i = 0; i < col; i++)
            if(matrix[0][i] == 0) setFirstRow = true;

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
            
        for(int i = 1; i < row; i++){
            if(matrix[i][0] == 0)
                for(int j = 1; j < col; j++) matrix[i][j] = 0;
        }
        for(int j = 1; j < col; j++){
            if(matrix[0][j] == 0)
                for(int i = 1; i < row; i++) matrix[i][j] = 0;
        }
        
        if(setFirstRow){
            for(int i = 0; i < col; i++) matrix[0][i] = 0;
        }
        if(setFirstCol){
            for(int i = 0; i < row; i++) matrix[i][0] = 0;
        }
    }