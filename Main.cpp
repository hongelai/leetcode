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
int grayCode1(char *s1, char *s2) {
  if (strlen(s1) != strlen(s2)) return -1;
  int count = 0;
  for (int i = 0; i < strlen(s1); i++){
    if(s1++ == s2++) continue;
    else count++;
  }
  return count == 1 ? 1: -1;
}
    void grayCode(int n) {
        vector<int> res(1<<n);
        for(int i = 0; i < 1<<n; i++){
            res[i] = (i >> 1) ^ i; //GrayCode(n) = B(n) XOR B(n+1). B(n)表示n的二进制，B(n+1)表示n右移一位的二进制
            cout<<res[i]<<" ";
          }
    }
int main ()
{
	int A[] = {1,3,7,13,23};
  int B[] = {2,7,8,33,44,55};
  int m = 0, n = 2;
  int C[] = {1};
  int start = -1, end = 1;
  while(end - start > 1) {
    cout<<"end"<<endl;
  }
	return 0;
}
