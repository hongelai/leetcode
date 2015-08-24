    int numIslands(vector<vector<char>> &grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1'){ 
                    bfs(grid, i, j);
                    count++;
                }
            }
        return count;
    }
    void bfs(vector<vector<char>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int> > q;
        q.push(make_pair(i,j));
        unordered_map<int, set<int> > map;
        map[i].insert(j);
        
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            grid[x][y] = '0';
            q.pop();
            
            if(x-1 >= 0 && map[x-1].count(y) == 0 && grid[x-1][y] == '1') {
                q.push(make_pair(x-1, y)); map[x-1].insert(y);
            }
            if(x+1 < m && map[x+1].count(y) == 0 && grid[x+1][y] == '1') {
                q.push(make_pair(x+1, y)); map[x+1].insert(y);
            } 
            if(y-1 >= 0 && map[x].count(y-1) == 0 && grid[x][y-1] == '1') {
                q.push(make_pair(x, y-1)); 
                map[x].insert(y-1);
            } 
            if(y+1 < n && map[x].count(y+1) == 0 && grid[x][y+1] == '1') {
                q.push(make_pair(x, y+1)); 
                map[x].insert(y+1);
            }
        }
    }



    //
int numIslands(vector<vector<char>> &grid) {
        if(grid.empty()) return 0;
        int M = grid.size(), N = grid[0].size();
        int numIsland = 0;
        for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            if(grid[i][j] == '1'){
                numIsland++;
                dfs(grid,i,j);
            }
    return numIsland;
}

void dfs(vector<vector<char>> &grid, int row, int col){
    const int M = grid.size(), N = grid[0].size();
    grid[row][col] = '0';

    if(row-1>=0 && grid[row-1][col] == '1')
        dfs(grid,row-1,col);
    if(row+1<M && grid[row+1][col] == '1')
        dfs(grid,row+1,col);
    if(col-1>=0 && grid[row][col-1] == '1')
        dfs(grid,row,col-1);
    if(col+1<N && grid[row][col+1] == '1')
        dfs(grid,row,col+1);
}