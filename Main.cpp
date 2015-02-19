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

void dfs(vector<vector<float> > &res, vector<float> &entry, float target, vector<float> coin, bool &found) {
    if(target == 0){
      res.push_back(entry);
      for(int i = 0; i < res[res.size() - 1].size(); i++) cout<< res[res.size() - 1][i] << " ";
       cout<<endl;
      found = true;
      return;
    }
    // for(int i = 0; i < res.size(); i++) cout<< res[i] << " ";
    //   cout<<endl;
    for(int i = 0; i < coin.size(); i++) {
      if(!found && coin[i] <= target) {
        cout<<target<<endl;
        entry.push_back(coin[i]);
        dfs(res, entry, target - coin[i], coin, found);
        entry.pop_back();
      }
      // if(found) break;
    }
}
vector<float> exchangeMoney(vector<float> coin, float target) {
    vector<vector<float> > res;
    vector<float> entry;
    if(coin.size() == 0 || target == 0) return entry;
    bool found = false;
    sort(coin.begin(), coin.end(), greater<float>());
    dfs(res, entry, target, coin, found);
    return res[0];
}
int main ()
{
	float A[] = {5, 1, 0.25, 0.1, 0.05, 0.01};
  vector<float> v(A,A+6);
  exchangeMoney(v,9.99);
	return 0;
}
