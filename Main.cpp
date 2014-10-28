#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <sstream>
#include <regex>
#include <limits>
using namespace std;

int longestCommonSubstring(string &a, string &b){
    int len1 = a.length();
    int len2 = b.length();
    int maxLen[len1+1][len2+1];
    
    if(len1 == 0 || len2 == 0) return 0;
    for(int i = 0; i <= len1; i++) maxLen[i][0] = 0;
    for(int i = 0; i <= len2; i++) maxLen[0][i] = 0;
    
    for(int i = 1; i <= len1; i++)
        for(int j = 1; j <= len2; j++)
        {
            if(a[i-1] == b[j-1])  maxLen[i][j] = maxLen[i-1][j-1] + 1;
            else                  maxLen[i][j] = max(maxLen[i-1][j], maxLen[i][j-1]);
        }
    return maxLen[len1][len2];
}
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
int main ()
{

	int array[8]={10,1,3,5,5,2};
	vector<int> v(array,array+6);

    cout<<maxSum(v,3)<<endl;

	system("pause");

	return 0;
}
