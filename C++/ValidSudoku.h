    bool isValidSudoku(vector<vector<char> > &board) {
        
        vector<bool> used(9,false);
        
        for(int i = 0; i < 9 ; i++){
            fill(used.begin(),used.end(),false);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.')
                    if(used[board[i][j]-'1']) return false;
                    else used[board[i][j]-'1'] =true;
            }
            
            fill(used.begin(),used.end(),false);
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.')
                    if(used[board[j][i]-'1']) return false;
                    else used[board[j][i]-'1'] =true;
            }
            
            fill(used.begin(),used.end(),false);
            for(int j = 0; j < 9; j++){ //第i个3X3小方格的第j个数
                int x = (i/3)*3 + j/3;//row
                int y = (i%3)*3 + j%3;//col
                if(board[x][y] != '.')
                    if(used[board[x][y]-'1']) return false;
                    else used[board[x][y]-'1'] = true;
            }
        }
        return true;
    }