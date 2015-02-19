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

void dfs(vector<string> &res, string &path, int index, const string &s, 
                          vector<int> &position, vector<char> &letters, vector<bool> used) {
  if (index == position.size())
  {
    res.push_back(path);
    cout<<path<<endl;
    return;
  }
  int lastIndex = -1;
  for (int j = 0; j < letters.size(); ++j)
  {
    if(lastIndex != -1 && letters[lastIndex] == letters[j]) continue;// 同一个位置不允许相同的字母
    if (!used[j] ) 
    {
      lastIndex = j;
      used[j] = true;
      char c = path[position[index]];
      path[position[index]] = letters[j];
      dfs(res, path, index + 1, s, position, letters, used);
      path[position[index]] = c;
      used[j] = false;
    }
  }
}

vector<string> permuteLowerCase(string s){
  vector<string> res; 
  if (s.length() == 0) return res;
  vector<int> position;
  vector<char> letters;
  string path = s;

  for (int i = 0; i < s.length(); ++i)
  {
    if (s[i] <= 'z' && s[i] >= 'a')
    {
      letters.push_back(s[i]);
      position.push_back(i);
    }
  }
  sort(letters.begin(), letters.end());
  vector<bool> used(letters.size(),false);
  dfs(res, path, 0, s, position, letters, used);

  return res;
}
int main ()
{
	float A[] = {5, 2};
  vector<int> v(A,A+2);
  permuteLowerCase("abcCb");
	return 0;
}
