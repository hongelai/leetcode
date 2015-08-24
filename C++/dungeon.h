    //从后往前推，minInitHealth表示从i ， j 到达 m， n所需的minHP
    //从后往前的好处：可以先计算出所需，遇到正数的时候就可以减去所需，就不需要记录还剩多少能量。
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
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        // hp[i][j] represents the min hp needed at position (i, j)
        // Add dummy row and column at bottom and right side
        vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
        hp[M][N - 1] = 1;
        hp[M - 1][N] = 1;
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
    }
