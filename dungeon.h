    //从后往前推，
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<int> minInitHealth(col+1, INT_MAX);
        minInitHealth[col-1] = 1; // do not init as minInitHealth[col] because this col will not be update and always be compare in the column col-1
        for (int i = row  - 1; i >=0; i--)
            for (int j = col - 1; j >= 0; j--) {
                minInitHealth[j] =max(1,min(minInitHealth[j+1],minInitHealth[j]) - dungeon[i][j]);
            }
            
        return minInitHealth[0];
    }