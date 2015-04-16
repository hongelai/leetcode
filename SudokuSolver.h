    typedef vector<vector<char> > Matrix;
    void solveSudoku(vector<vector<char> > &board) {
        solveSudokuRe(board, 0, 0);
    }
    bool solveSudokuRe(Matrix &board, int row, int col){
        getNext(board, row, col); //update row and col 
        if (row == 9) {
            return true;
        }
        vector<bool> avail(9, true);
        getAvailable(board, avail, row, col);//update avail array
        for (int i = 0; i < 9; i++) { // find a solution for this coordinate
            if(!avail[i]) continue;
            board[row][col] = i + '1';
            if (solveSudokuRe(board, row, col)) return true;
        }
        board[row][col] = '.'; //if no solution for (row, col), return to last coordinate
        return false;
    }
    void getNext(Matrix &board, int &row, int &col){
        while(row < 9){
            if(board[row][col] == '.') return;
            row = col == 8 ? row + 1 : row;
            col = (col + 1) % 9;
        }
    }
    void getAvailable(Matrix &board, vector<bool> &avail, int row, int col){ //return available choices for (row, col)
        for(int i = 0; i < 9; i++){ //vertical and horizonal
            if(board[row][i] != '.') avail[board[row][i] - '1'] = false;
            if(board[i][col] != '.') avail[board[i][col] - '1'] = false;
            // int box_i = row/3*3 + i/3, box_j = col/3*3 + i%3; //smart but hard to think of
            // if (board[box_i][box_j] != '.') avail[board[box_i][box_j]-'1'] = false;
        }
        int rowIndex = row - row%3;
        int colIndex = col - col%3;
        for(int i = rowIndex; i < rowIndex + 3; i++)
            for(int j = colIndex; j < colIndex + 3; j++){
                if(board[i][j] != '.') avail[board[i][j] - '1'] = false;
            }
                
    }