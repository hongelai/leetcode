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
bool hasSame(string::iterator f1, string::iterator e1, string::iterator f2, string::iterator e2){
        int chars[256] = {0};
        for (;f1 != e1;) chars[*f1++]++;
        for (;f2 != e2;) chars[*f2++]--;
        for (int i = 0; i < 256; i++) if(chars[i] != 0) return false;
        return true;
    }

int main ()
{
  int a[] = {1,1,1,0,2,4,2,5,6,7,2,2,3,3,2,1,2};
  std::vector<int> v(a, a+17);
  string s1= "hello", s2 = "heo0l";
  cout<<"coming"<<endl;
  cout<<hasSame(s1.begin(), s1.end(),s2.begin(),s2.end())<<endl;

	return 0;
}
