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
string longestSubstringWithTwoChar(string s){
	int set[256]; // store the last occur index of charactor i
	int len = s.length();
	string res = "";
	int start = 0, end = 0, count = 0;
	char charA = -1, charB = -1; // record this unique character

	for(int i = 0; i < 256; i++) set[i] = -1;
	while(end < len){
		
		if(set[s[end]] == -1){ // if is a new charactor between [start,end]
			count++;
			if(count <= 2){
				if (charA == -1) charA = s[end];
				else charB = s[end];
			}else{ // a,b,a,a,a,a,a,a,a,c,a,a,a,a,a,
				int nextIndex;
				if (set[charA] > set[charB])
				{
					nextIndex = set[charB] + 1;
					set[charB] = -1;
					charB = s[end];
				}else{
					nextIndex = set[charA] + 1;
					set[charA] = -1;
					charA = s[end];
				}
				start = nextIndex;
				count--;
			}
			
		}
		if(res.length() <= end - start + 1) res = s.substr(start,end - start + 1);
		set[s[end]] = end;
		end++;
	}
	return res;
}

int main ()
{

	int a[] = {1,1,2,2,3,2,4,5,5,4,6,7,6};
    vector<int> vt(a,a+13) ;

	cout<<longestSubstringWithTwoChar("aabbcbbbadef")<<endl;
	return 0;
}
