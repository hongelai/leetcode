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
struct greaterthan{
  bool operator() (pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
}greaterthan;
vector<int> findTopKth(vector<int> v, int k){
    int size = v.size();
    unordered_map<int,int> map;
    vector<pair<int,int> > pairs;
    vector<int> ret;

    // auto lessthan = [=](pair<int, int> a, pair<int, int> b){return a.second < b.second;};
    for(int i = 0; i < size; i++) map[v[i]]++;
    for(auto it = map.begin(); it != map.end(); it++) pairs.push_back(make_pair(it->first, it->second));
    sort(pairs.begin(), pairs.end(), greaterthan);
    for(int i = 0; i < k && i < pairs.size(); i++){
      ret.push_back(pairs[i].first);
      cout<<ret[i]<<" ";
    }
    return ret;
}
struct comp{
  bool operator() (pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

void FindKth(vector<int> v, int k) {
  int size = v.size();
  priority_queue<pair<int,int>, vector<pair<int,int> >, comp > q;
  int start = 0, end = 0, count = 0;
  
  sort(v.begin(), v.end());
  int index = 0;
  while (end < size) {
      while (end == 0 || (end < size && v[end] == v[start])) end++;
      int dist = end - start;
      q.push(make_pair(v[start], dist));
      count++;
      if(count > k) q.pop();
      start = end;
  }
  while (!q.empty()) {
    cout<<q.top().first<<" ";
    q.pop();
  }

}

int main ()
{
  int a[] = {1,1,1,0,2,4,2,5,6,7,2,2,3,3,2,1,2};
  std::vector<int> v(a, a+17);
  FindKth(v, 3);
	return 0;
}
