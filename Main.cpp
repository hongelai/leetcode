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

void findFirstUnique(vector<int> &v){

	unordered_map<int,int> map;
	for(int i = 0; i < v.size(); i++){
		if(map.find(v[i]) == map.end()){
			// um.insert(make_pair(a,1)); // cannot use insert again(duplicate), because !um[v[i]] will innitialize it as 0.
			map[v[i]] = 1;
		}
		else map[v[i]]++;
	}
	for(auto it = v.begin();it != v.end(); it++) 
		if(map[*it] == 1) cout<<*it<<" ";

}
string letterCombination(string s){
	string res = "";
	if(s.empty()) return res;
 	unordered_map<char,vector<char> > map;
	char a1[] = {'a', 'b', 'c' };
	char a2[] = {'d','e','f'};
	char a3[] = {'g','h','i'};
	char a4[] = {'j','k'};
	map['1'].assign(a1,a1+3);
	map['2'].assign(a2,a2+3);
	map['3'].assign(a3,a3+3);
	map['#'].assign(a4,a4+2);
	int start = 0, end = 0, len = s.length();

	while(end < len){
		while(s[start] == s[end] && s[end] != '\0') end++;
		int distance = end - start;
		if(s[start] != '#' && s[start] != '0') res.append(1,map[s[start]][distance-1]);
		start = end;
	}

	return res;
}

int main ()
{
	int a[] = {1,-1,20,12,-300,900,-901,5,5,4,6,7,6};
    vector<int> vt(a,a+13) ;
    
    cout<< letterCombination("222#1312000111");
	return 0;
}
