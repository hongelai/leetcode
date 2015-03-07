  //accepted 16ms
   int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        int col = row;
        vector<int> res;
        res.resize(col,INT_MAX);
        mini(triangle,row,res);
        return *min_element(res.begin(),res.end());
    }
    void mini(vector<vector<int> > &triangle, int depth, vector<int> &res){
        int row = depth;
        int col = triangle[row-1].size();
        
        if(row == 1){
            res[0] = triangle[0][0];
            return;
        }
        
        mini(triangle,row-1,res);
        for(int i = col-1; i >= 0; i--){
            int small;
            if(i == col){
                small = res[col-1];
            }else if( i == 0){
                small = res[0];
            }else{
                small = min(res[i],res[i-1]);
            }

            res[i] = triangle[row-1][i] + small;
        }
    }
    
    //bottom up
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size(), col = triangle[0].size();
        for (int i = row - 1; i >0; i--)
            for (int j = 0; j < triangle[i].size() - 1; j++)
                triangle[i-1][j] += min(triangle[i][j], triangle[i][j+1]);
        return triangle[0][0];
    }