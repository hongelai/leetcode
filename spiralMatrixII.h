    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n,vector<int>(n));
        if(n == 0) return res;
        
        int rMin = 0, rMax = n-1;
        int cMin = 0, cMax = n-1;
        
        int index = 1;
        while(true){
            for(int c = cMin; c <= cMax; c++) res[rMin][c] = index++;
            if(++rMin > rMax) break;
            
            for(int r = rMin; r <= rMax; r++) res[r][cMax] = index++;
            if(cMin > --cMax) break;
            
            for(int c = cMax; c >= cMin; c--) res[rMax][c] = index++;
            if(rMin > --rMax) break;
            
            for(int r = rMax; r >= rMin; r--) res[r][cMin] = index++;
            if(++cMin > cMax) break;
        }
        return res;
    }