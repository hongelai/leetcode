#include <iostream>
//#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <stack>
#include <sstream>
#include <map>
#include <limits>
#include <unordered_set>
#include <string.h>
#include <string>
#include <queue>

using namespace std;

int findFirstUnique(vector<int> &v){

	unordered_map<int,int> um;
	unordered_set<int> us;
	for(int i = 0; i < v.size(); i++){
		if(!um[v[i]]){
			// um.insert(make_pair(a,1)); // cannot use insert again(duplicate), because !um[v[i]] will innitialize it as 0.
			um[v[i]] = 1;
			us.insert(v[i]);
		}
		else{
			um[v[i]]++;
			us.erase(v[i]);
		}
	}
	// for(auto it = um.begin();it!=um.end();it++) cout<<it->first<<" "<<it->second<<endl;
	for(auto it = us.begin();it!=us.end();it++) cout<<*it<<" ";

	return *us.begin();
}
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
        cout<<low<<endl;
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
int main ()
{
    vector<vector<int> > res {{1},{3}};
    cout<<searchMatrix(res,3);
	return 0;
}
