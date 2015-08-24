int Num(vector<int> &v,int start, int end){
    int sum = 0;
    for(int i = end-1,j = 0; i >= start-1 && i >= 0  ; i--,j++)
        sum += v[i]*pow(10,j);
    
    return sum;
}
int maxSum(vector<int> v, int m){
    int val[m+1][v.size()+1];  //
    for(int i = 0; i <= v.size(); i++) val[0][i] = Num(v,0,i);

    int minVal = numeric_limits<int>::max();
    
    //V(m,n) = Min(V(m-1,i)+Num(i+1,n))  i = m,..,n-1
    for(int i = 1; i <= m; i++){ //m
        for(int j = i+1; j <= v.size(); j++){ //n
            for(int k = i; k < j; k++)//cal the Min
                minVal = min(val[i-1][k]+Num(v,k+1,j),minVal);
            val[i][j] = minVal; 
            minVal = numeric_limits<int>::max();   
        }
        
    }
    return val[m][v.size()];
}