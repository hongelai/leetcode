    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.resize(rowIndex+1);
        
        for(int i=0; i <= rowIndex; i++){
            res[0] = res[i] = 1;
            for(int j = i-1; j > 0;j--){
                res[j] = res[j-1]+res[j];
            }
        }
        return res;
    }