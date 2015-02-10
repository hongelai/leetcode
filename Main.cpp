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
 int numDistinct_2(string S, string T) {
        int M = S.size();
        int N = T.size();
        vector<int> dp(N + 1);
        dp[0] = 1;
        for (int i = 1; i <= M; ++i) {
            for (int j = N; j >=1; --j) {
                dp[j] = dp[j] + (S[i-1] == T[j-1] ? dp[j-1] : 0);
            }
        }
        return dp[N];
    }
 int numDistinct_1(string S, string T) {
        int M = S.size();
        int N = T.size();
        vector<vector<int> > dp(M+1, vector<int>(N+1));
        for (int j = 0; j <= N; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 0; i <= M; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = dp[i-1][j] + (S[i-1] == T[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[M][N];
    }
int main ()
{
	int a[] = {5,4,1,2,3,1,4,5};
    vector<int> vt(a,a+8) ;
    cout<<numDistinct_1("abc","abd")<<endl;
	return 0;
}
