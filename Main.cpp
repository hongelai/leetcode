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
    void dfs(int n, int k, int index, vector<int> &entry, vector<vector<int> > &res){
        if(entry.size() == k){
            res.push_back(entry);
            for(auto it = entry.begin(); it != entry.end(); it++) cout<<*it<<" ";
            cout<<endl;
            return;
        } 
        
        for(int i = index; i < n+1; i++){
            entry.push_back(i);
            dfs(n,k,i+1,entry,res);
            entry.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> entry;
        dfs(n,k,1,entry,res);
        return res;
    }
int main ()
{

    auto it = combine(4,2);
	return 0;
}
