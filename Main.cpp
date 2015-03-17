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
#include <utility> 
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
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        int size = L.size();
        int len = S.length();
        int wordLen, start = 0, winSize;
        unordered_map<string, int> map;
        unordered_map<string, int> winMap;
        
        if (size == 0) return ret;
        else {
            wordLen = L[0].length();
            winSize = wordLen*size;
        }
        if (winSize > len) return ret;
        for (int i = 0; i < size; i++) map[L[i]]++;
        
        while (start + winSize <= len) {
            int index = 0;
            string winStr = S.substr(start, winSize);
            while (index + wordLen <= winSize) {
                string sub = winStr.substr(index, wordLen);
                if (map.count(sub) == 0) {
                    break;
                } else {
                    winMap[sub]++;
                    if(winMap[sub] > map[sub]) break;
                    index += wordLen;
                }
            }
            if (index == winSize) {
                ret.push_back(start);
                cout<<start<<endl;
//                start += winSize;
                  start+= wordLen;
            } else {
//                start += index + wordLen;
                  start+=wordLen;
            } 
            winMap.clear();
        }
        return ret;
    }
int main ()
{
  string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
  string a[] = {"fooo","barr","wing","ding","wing"};
  vector<string> v(a,a+5);
  findSubstring(S,v);
  return 0;
}
