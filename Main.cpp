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
vector<int> split(string source, char del){
    int index = 0,pos = -1;
    vector<int> res;
    while((pos = source.find(del,index)) != -1){
        res.push_back(stoi(source.substr(index,pos-index)));
        index++;
    }
    return res;
}
int main ()
{
    int aa[]={1,1,1,0};
    
    vector<int> vc(aa,aa+4);
    string str = "12.12.3";
    vector<int > rs = split(str,'.');
    for(int i = 0; i < rs.size();i++) 
            cout<<rs<<" ";

	system("pause");


	return 0;
}
