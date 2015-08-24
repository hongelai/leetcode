    int totalNQueens(int n) {
        int res = 0;
        vector<int> col(n,0);
        vector<int> md(2*n-1,0);// main diag, calculate from row + col
        vector<int> ad(2*n-1,0);
        
        dfs(0,n,res,col,md,ad);
        return res;
    }
    void dfs(int row, int n, int &res, vector<int> &col, vector<int> &md, vector<int> &ad){
        if(row == n){
            res++;
        }
        for(int i = 0; i < n; i++){
            if(col[i] == 1 || md[row+i] == 1 || ad[row+n-i] == 1) continue;
            col[i] = md[row+i] = ad[row+n-i] = 1;
            dfs(row+1,n,res,col,md,ad);
            col[i] = md[row+i] = ad[row+n-i] = 0;
        }
    }