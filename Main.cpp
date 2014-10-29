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
int longestSkatingDistance(int a[5][5],int m,int n)
{
    multimap<int,pair<int,int>> mp;
    for(int i = 0; i < m; i++)
       for(int j = 0; j < n; j++){
           int tmp = a[i][j];
           mp.insert(make_pair(tmp, make_pair(j,i)));
       }  
       
    int result[m][n];
    result[0][0] = 0;
    int maxResult = 0;
    for(auto it = mp.begin(); it != mp.end();it++){
        int x = (it->second).first;
        int y = (it->second).second;
        int mm = 0;
        if(x-1 >= 0 && a[y][x-1] < it->first) mm = max(mm,result[y][x-1] + 1);
        if(x+1 < n && a[y][x+1] < it->first) mm = max(mm,result[y][x+1] + 1);
        if(y+1 < m && a[y+1][x] < it->first) mm = max(mm,result[y+1][x] + 1);
        if(y-1 >= 0 && a[y-1][x] < it->first) mm = max(mm,result[y-1][x] + 1);
        
        result[y][x] = mm;
        if(mm>maxResult) maxResult = mm;
    }               
 
    return maxResult;
}          
int main ()
{

	int array[5][5]={{1,2,3,4,5},
                     {16,17,18,19,6},
                     {15,26,25,20,7},
                     {14,23,22,21,8},
                     {13,12,11,10,9}};
    cout<<longestSkatingDistance(array,5,5)<<endl;    
           
	system("pause");

	return 0;
}
