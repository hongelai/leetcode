#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <stack>
#include <sstream>
#include <regex>
#include <limits>
#include <unordered_set>
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
int main ()
{

	int array[]={1,2,2,3,4,3,1,5,3,11};
	vector<int> v(array,array+10);
cout<<NULL<<endl;      
       
	system("pause");


	return 0;
}
