    vector<vector<string> > solveNQueens(int n) {
        vector<string> sol;
        vector<int> col(n, 0);
        vector<int> mainDiag(n*2 -1, 0); // row + col
        vector<int> antiDiag(n*2 -1, 0); // row + N - col
        if(n < 1) return res;
        dfs(0,n,sol,col,mainDiag,antiDiag);
        
        return res;
    }
    void dfs(int row, int n, vector<string> &sol, vector<int> &col, vector<int> &md, vector<int> &ad){
        if(sol.size() == n){
            res.push_back(sol);
        }
        string s(n,'.');
        for(int i = 0; i < n; i++){
            if(col[i] != 0 || md[row+i] != 0 || ad[row+n-i] != 0) continue;
            s[i] = 'Q';
            sol.push_back(s);
            col[i] = md[row+i] = ad[row+n-i] = 1;
            dfs(row+1,n,sol,col,md,ad);
            col[i] = md[row+i] = ad[row+n-i] = 0;
            sol.pop_back();
            s[i] = '.';
        }
    }
    vector<vector<string> > res;