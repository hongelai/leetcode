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

    string minWindow(string S, string T) {
        int sLen = S.length(), tLen = T.length();
        int start = 0, end = 0, count = 0, minLen = INT_MAX;
        string ret = "";
        unordered_map<char, int> need, find;
        
        if (sLen < tLen) return ret;
        for(int i = 0; i < tLen; i++) need[T[i]]++;
        
        while (end < sLen) {
            if (need.count(S[end]) == 0){
                end++;
                continue;
            } 
            find[S[end]]++;
            if (find[S[end]] <= need[S[end]]) count++;
            cout<<find[S[end]]<<" "<<count<<endl;
            if (count == tLen) {
                while (need.count(S[start]) == 0 || need[S[start]] < find[S[start]]) {
                    find[S[start]]--;
                    start++;
                }
                cout<<"in"<<endl;
                int len = end - start + 1;
                if (minLen > len) {
                    minLen = len;
                    ret = S.substr(start, len);
                    cout<<ret<<endl;
                }
            }
            end++;
        }
        return ret;
    }
int main ()
{
  int a[] = {1,4,5,7,10,12,33,35};
  minWindow("bba", "ab");
	return 0;
}
