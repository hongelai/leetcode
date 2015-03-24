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
string repeated_substring(string str) {
    int len = str.length();
    int dp[len][len];
    for (int i = 0; i <= len; ++i) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    int max_len = 0, index = len + 1;
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            if (str[i-1] == str[j-1] && abs(i-j) > dp[i-1][j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    index = min(i, j);
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    cout<<dp[3][5]<<endl;
    return max_len > 0 ? str.substr(index - max_len, max_len) : "";
}
string longestCommonPrefix(string s1, string s2) {
  string s = "";
  int size = min(s1.length(), s2.length());
  if (size == 0) return s;
  for (int i = 0; i < size; i++) {
    if (s1[i] != s2[i]) return s1.substr(0, i); 
  }
  return s1.substr(0, size);
}
string longestRepeatedSubstring(string s){
  vector<string> sub; //suffix array
  int len = s.length();
  for (int i = 0; i < len; i++) {
    string str = s.substr(i, len-i);
    cout<<str<<endl;
    sub.push_back(str);
  }
  sort(sub.begin(), sub.end());
  string ret = "";
  for (int i = 0; i < len - 1; ++i)
  {
    string x = longestCommonPrefix(sub[i], sub[i+1]);
    if (x.length() > ret.length())
    {
       ret = x;
    }
  }
  return ret;
}
int main ()
{
  int a[] = {1,2};
  std::vector<int> v(a, a+2);
  // combinationSum2(v, 3);
  string str = "ababa";
  cout<<longestRepeatedSubstring(str);

	return 0;
}
