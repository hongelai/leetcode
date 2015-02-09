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

bool isAnagram(string a, string b){
	int count[256] = {0};
  for (int i = 0; i < a.length(); ++i) count[a[i]]++;
  for (int i = 0; i < b.length(); ++i) count[b[i]]--;
  for (int i = 0; i < 256; ++i)
  {
    if (count[i] != 0)
    {
      return false;
    }
  }
  return true;
}

int findMaxWindow(string a, string b){
	int len = a.length();
	int start = 0, end = len - 1;
	
	for(int ws = len; ws > 0; ws--)
		for(int i = 0; i + ws - 1 < len; i++){
			string str1 = a.substr(i, ws);
			string str2 = b.substr(i, ws);
			if(isAnagram(str1, str2)) return ws;
		}
	return -1;
}
bool oneEditDistance(string a, string b){
	if (a.length() > b.length()) swap(a ,b);
	if (b.length() - a.length() > 1) return false;

	bool haveOne = false;
	for (int i = 0, j = 0; i < a.length(); i++, j++) { //
		if (a[i] != b[j]) {
			if (haveOne) {
				return false;
			} else {
				haveOne = true;
				if(a.length() < b.length()) i--;
			}
		}
	}
	cout<<"out"<<endl;
	return haveOne || a.length() < b.length(); // 处理前缀 abc abcd,
}
int main ()
{
<<<<<<< HEAD
	int a[] = {5,4,1,2,3,1,4,5};
    vector<int> vt(a,a+8) ;

	return 0;
}
