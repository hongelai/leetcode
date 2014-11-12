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
#include <unordered_map>
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

int main ()
{

	int array[]={1,2,2,3,4,3,1,5,3,11};
	vector<int> v(array,array+10);

	cout<<findFirstUnique(v)<<endl;
	// unordered_map<int,pair<int,int> > um;
	// um.insert(make_pair(1,make_pair(2,3)));
	// um.insert(make_pair(2,make_pair(32,4)));
	// um.insert(make_pair(3,make_pair(21,22)));
	// auto it = um.begin();
	// for(;it!=um.end();it++)
	// 	cout<<(it->second).first<<"  ";
	return 0;
}
