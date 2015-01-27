    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty()) return res;
        
        int iMax = matrix.size()-1, jMax = matrix[0].size()-1; //bottom and right bound
        int iMin = 0,jMin = 0; // left amd upper bound
 
        while(true){
            for(int j = jMin; j <= jMax; j++) res.push_back(matrix[iMin][j]);
            if(++iMin > iMax) break;
            
            for(int i = iMin; i <= iMax; i++) res.push_back(matrix[i][jMax]);
            if(jMin > --jMax) break;
            
            for(int j = jMax; j >= jMin; j--) res.push_back(matrix[iMax][j]);
            if(iMin > --iMax) break;
            
            for(int i = iMax; i >= iMin; i--) res.push_back(matrix[i][jMin]);
            if(++jMin > jMax) break;
        }
        return res;
    }