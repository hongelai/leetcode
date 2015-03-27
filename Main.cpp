#include <iostream>
//#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>
#include <sstream>
#include <map>
#include <limits>
#include <unordered_set>
#include <string.h>
#include <string>
#include <deque>
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
/*
vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int size = num.size();
        vector<vector<int> > ret;
        unordered_map<int, vector<vector<int> > > map; 
        unordered_map<int, int> dict;
        
        sort(num.begin(), num.end());
        ret.resize(1);
        map[0] = ret; 
        for (int i = 0; i < size; i++) dict[num[i]]++;
        for (int i = 1; i <= target; i++) {
            vector<vector<int> > entry;
            map[i] = entry;
            for (int j = 1; j <= i; j++) {  // num[?] == i-j
                if (dict.count(i-j+1) != 0 && dict[i-j+1] > 0) {
                    dict[i-j+1]--;
                    for (const auto& v : map[j-1]){
                        vector<int> tmp = v;
                        tmp.push_back(i-j+1);
                        map[i].push_back(tmp);
                    }
                }
            }
        }
        cout<<map[0].size()<<endl;
        map[target].erase(unique(map[target].begin(), map[target].end()), map[target].end());

        return map[target];
    }
*/
#define  IN_BOARD(a,b) (a >=0 && a < m && b >= 0 && b < n)
int minDistance(int board[][5], int m, int n){
  int minL = 100000;
  queue<pair<int, int> > q;
  vector<vector<int> > dist(m, vector<int>(n,-1));// -1 unvisited
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
    {
      if(board[i][j] == 3){
          q.push(make_pair(i,j));
          dist[i][j] = 0;
         }
    }


  while (!q.empty()) {

    int x = q.front().first, y = q.front().second;
    // cout<<board[x][y]<<endl;
    if (board[x][y] == 0) break;
    q.pop();
    if (IN_BOARD(x-1,y) && (board[x-1][y] == 1 || board[x-1][y] == 0) && dist[x-1][y] == -1){
      dist[x-1][y] = dist[x][y] + 1;
      q.push(make_pair(x-1, y));
    }
    if (IN_BOARD(x+1,y) && (board[x+1][y] == 1 || board[x+1][y] == 0) && dist[x+1][y] == -1){
      dist[x+1][y] = dist[x][y] + 1;
      q.push(make_pair(x+1, y));
    }
    if (IN_BOARD(x,y-1) && (board[x][y-1] == 1 || board[x][y-1] == 0) && dist[x][y-1] == -1){
      dist[x][y-1] = dist[x][y] + 1;
      q.push(make_pair(x, y-1));
    }
    if (IN_BOARD(x,y+1) && (board[x][y+1] == 1 || board[x][y+1] == 0) && dist[x][y+1] == -1){
      dist[x][y+1] = dist[x][y] + 1;
      q.push(make_pair(x, y+1));
    }
  }
  cout<<"fsdfsdfsd"<<endl;
    for (int i = 0; i < m; ++i){
      for (int j = 0; j < n; ++j)
      {
        cout<<dist[i][j]<<" "; 
      }
      cout<<endl;
    }
}
int priority(char c){
  if(c == '^') return 1;
  else if(c == '*' || c == '/') return 2;
  else if(c == '+' || c == '-') return 3;
}
string infixToPostfix(string s) {
  stack<char> st;
  string res = "";

  for (int i = 0; i < s.length(); i++) {
    if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
      while (!st.empty() && priority(st.top()) > priority(s[i])) {
        res.push_back(st.top());
        st.pop();
      }
      st.push(s[i]);
    } else if (s[i] == '(') {
      st.push(s[i]);
    } else if (s[i] == ')') {
      while (st.top() != '(') {
        res.push_back(st.top());
        st.pop();
      } else res.push_back(s[i]);
    }
  }
}
int main ()
{
  int a[] = {4,5,1,4,5,3,1,6,7,8,9,2};
  std::vector<int> v(a, a+12);
  int arr[5][5]={  {1,1,1,1,1},  //0 entry,  1 room, 2 obsta, 3 exit
                    {1,0,2,0,1},
                    {1,1,1,2,1},
                    {1,0,1,3,1},
                    {1,1,1,1,1}};
  cout<<minDistance(arr, 5,5)<<endl;
	return 0;
}
