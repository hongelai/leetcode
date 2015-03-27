    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return;
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                if((i == 0 || i == row-1 || j == 0 || j == col-1) && board[i][j] == 'O'){
                    bfs(i, j, board); //or dfs(board, i , j)
                }
            }
         for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
               board[i][j] = (board[i][j] == 'T' ? 'O':'X');
                
            }   
    }
    void bfs(int i, int j, vector<vector<char>> &board){
        int row = board.size();
        int col = board[0].size();
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(board[x][y] != 'O') continue;
            board[x][y] = 'T';    
            
            if(y-1 >= 0) q.push(make_pair(x,y-1)); // if add board[x][y] != 'O' time exceed
            if(y+1 < col) q.push(make_pair(x,y+1));
            if(x-1 >= 0) q.push(make_pair(x-1,y));
            if(x+1 < row) q.push(make_pair(x+1,y));

        }
    }

    void dfs(BOARDTYPE &board, int row, int col) {
        int N = board.size(), M = board[0].size();
        if (row < 0 || row >= N || col < 0 || col >= M) return;
        if (board[row][col] != 'O') return;
        board[row][col] = 'V';
        dfs(board, row+1, col);
        dfs(board, row-1, col);
        dfs(board, row, col+1);
        dfs(board, row, col-1);
    }