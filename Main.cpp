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

    bool isMatch(const char *s, const char *p) {
        const char* sBackup = NULL, *pBackup = NULL;
        cout<<s<<" "<<p<<endl;
        while(*s != '\0'){
            if(*p == '?' || *s == *p){
                s++;
                p++;
            }else if(*p == '*'){
                pBackup = p++;
                if(*p == '\0') return true;  //相当与匹配全部
                sBackup = s; //相当于先匹配 0个，之后可能会逐渐加
                
            }else{
                if(!pBackup) return false;
                p = pBackup;
                s = sBackup;
                s++;
            }
        }
        if(*p == '\0') return true;
        else{
            while(*p != '\0')
                if(*p++ != '*')
                    return false;
            return true;
        }
    }
int main ()
{
  int a[] = {1,1,1,0,2,4,2,5,6,7,2,2,3,3,2,1,2};
  std::vector<int> v(a, a+17);
  char aa[] = "aaaab", b[] = "a*";
  cout<<isMatch(aa,b)<<endl;

	return 0;
}
