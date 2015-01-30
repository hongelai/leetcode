    bool dfs(vector<vector<char> > &board, string word, int index, int y,int x,vector<vector<bool> > &visited){

        if(visited[y][x]) return false;
        
        if(board[y][x] != word[index]) return false;
        else{
            if(index == word.size()-1) return true;
            bool res = false;
            visited[y][x] = true;
            if(y-1 >=0)                                   res = res ||  dfs(board,word,index+1,y-1,x,visited);
            if(y+1 <=board.size()-1 && res == false)      res = res ||  dfs(board,word,index+1,y+1,x,visited);
            if(x-1 >= 0 && res == false)                  res = res ||  dfs(board,word,index+1,y,x-1,visited);
            if(x+1 <= board[0].size()-1 && res == false)  res = res ||  dfs(board,word,index+1,y,x+1,visited);
            
            //reset visited
            visited[y][x] = false;
            return res;
        }
    }
    bool exist(vector<vector<char> > &board, string word) {
        int col = board[0].size();
        int row = board.size();
        vector<vector<bool> > visited(row,vector<bool>(col,false));
       
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(dfs(board,word,0,i,j,visited))
                    return true;
        return false;
    }