    bool isValidSudoku(vector<vector<char> > &board) {
        
        vector<bool> used(9,false);
        
        for(int i = 0; i < 9 ; i++){
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
        }
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                fill(used.begin(),used.end(),false);
                
                for(int m = i; m < i+3; m++)
                    for(int n = j; n <j+3; n++){
                        if(board[m][n] != '.')
                            if(used[board[m][n]-'1']) return false;
                            else used[board[m][n]-'1'] =true;
                    }
            }
        }
        return true;
    }