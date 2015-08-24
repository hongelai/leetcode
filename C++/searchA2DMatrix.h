    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[row-1][col-1]) return false;
        
        //binary search in first column
        int desR,low = 0, high = row-1;
        while(low < high){
            int mid = (low + high) / 2;
            if(target < matrix[mid][0]) high = mid;
            else if(target > matrix[mid][0]){
                low = mid;
                if(low + 1 == high){
                    if(target >= matrix[high][0]) low = high;
                    else high = low;
                }
            } 
            else return true;
        }
        desR = low;
        low = 0; 
        high = col - 1;
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(target < matrix[desR][mid]) high = mid-1;
            else if(target > matrix[desR][mid]) low = mid+1;
            else return true;
        }
        return false;
        
    }
//optimal solution
    bool searchMatrix_2(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int N = matrix.size(), M = matrix[0].size();
        int i = 0, j = M * N - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            int row = mid / M, col = mid % M;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) i = mid + 1;
            else j = mid - 1;
        }
        return false;
    }