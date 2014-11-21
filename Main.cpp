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
#include <queue>
using namespace std;

int findFirstUnique(vector<int> &v){

	unordered_multimap<int,int> um;
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


    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        
        for(int i = 0; i < num.size(); i++){
            int target = 0-num[i];
            vector<int> tmp;
            unordered_multiset<int> map;
            
            for(int j = i+1; j < num.size(); j++){
                int second = target - num[j];
                auto pos = map.find(second);
                if(pos == map.end())
                    map.insert(num[j]);
                else{
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(second);
                    cout<<num[i]<<" "<<num[j]<<" "<<second<<endl;
                    res.push_back(tmp);
                    vector<int> empty;
                    tmp.swap(empty);
                }
            }
            
        }
        sort(res.begin(), res.end());

        res.erase(unique(res.begin(), res.end()), res.end());
        for(int i = 0; i < res.size(); i++){
            for(int j = 0; j < res[0].size();j++)
             cout<<res[i][j]<<" ";
             cout<<endl;
         }        
        return res;
    }
int main ()
{
    int aa[]={-1, 0, 1, 2, -1, -4};
    vector<int> vc(aa,aa+6);
    
    threeSum(vc);

	return 0;
}
