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
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	return a == b;
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
    void gen_path(unordered_map<string, vector<string> > &father, vector<string> &path, const string &start, const string &word,
              vector<vector<string> > &result) {
          path.push_back(word);
          if (word == start) {
          	  for (int i = 0; i < path.size(); ++i)
          	  {
          	  	cout<<path[i]<<" ";
          	  }
          	  cout<<endl;
              result.push_back(path);
              reverse(result.back().begin(), result.back().end());
          } else {
              for (int i = 0; i < father[word].size(); ++i) {
                  gen_path(father, path, start, father[word][i], result);
				}
			}
          path.pop_back();
      }
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> cur, next;
        unordered_set<string> visited;
        unordered_map<string, vector<string> > parent;
        vector<vector<string> > res;
        cur.insert(start);
        dict.insert(end);
        
        while(!cur.empty()){
          if (cur.count(end) != 0) {
              vector<string> path;
              gen_path(parent, path, start, end, res); 
              break;
          }
          for (const auto& node : cur) visited.insert(node);
          for (const auto& node : cur) {
              
              for (int i = 0; i < node.length(); i++) {
                  string tmp = node;
                  for (char j = 'a'; j <= 'z'; j++) {
                      tmp[i] = j;
                      if (!visited.count(tmp) && (dict.find(tmp) != dict.end())) {
                          next.insert(tmp);
                          if (tmp != end) visited.insert(tmp);
                          parent[tmp].push_back(node);
                      }
                  }
                  
              }
          }
          cur.clear();
          swap(cur, next);
        }
        return res;
    }

int main ()
{
	int a[] = {5,4,1,2};
  	vector<int> vt(a,a+13) ;
  	string str[] = {"ted","tex","red","tax","tad","den","rex","pee"};
  	unordered_set<string> v(str,str+8);
  	findLadders("red","tax",v);
	return 0;
}
