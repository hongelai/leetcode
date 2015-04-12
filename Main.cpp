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

int dfs(int a[][6], vector<vector<int> > &used, int x, int y, int m, int n){
  if(used[x][y] != 0) return used[x][y];
  int val = 0;

  if(x+1 < m && a[x+1][y] >= a[x][y] + 1) val  = max(val, dfs(a, used, x+1, y, m, n));
  if(x-1 >= 0 && a[x-1][y] >= a[x][y] + 1) val  = max(val, dfs(a, used, x-1, y, m, n));
  if(y+1 < n && a[x][y+1] >= a[x][y] + 1) val  = max(val, dfs(a, used, x, y+1, m, n));
  if(y-1 >= 0 && a[x][y-1] >= a[x][y] + 1) val  = max(val, dfs(a, used, x, y-1, m, n));
  used[x][y] = val+1;
  
  return used[x][y];
 }

int findLongestIncreasing(int a[][6], int m, int n){
  vector<vector<int> > used(m,vector<int>(n,0));
  int res = 0;
  int index = 0;
  for (int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
      
      int tmp = dfs(a, used, i, j, m,n);
      if(res < tmp) {
        res = tmp;
        cout<<i<<" "<<j<<endl;
      }
    }
    return res;
}
int findBad(vector<int> v) {
  int start = 0, end = v.size()-1;
  while(start <= end){
    int mid = (start + end) / 2;
    if(v[mid] == 2 && v[mid-1] == 1) return mid;
    else if(v[mid] == 1) start = mid+1;
    else end  = mid - 1;
  }
  return start;
}

int main ()
{
  int a[] = {1,1,1,1,1,1,2,2,2,2,2,2};
  vector<int> v(a,a+12);

	return 0;
}
