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
void letterCombinations(string digits) {
        int size = digits.length();
        string a[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> dict(a,a+10);
        vector<string> res;
        
        if (size == 0) cout<<"emdp"<<endl;
        res.push_back("");
        for (int i = 0; i < size; i++) {
            vector<string> temp;
            cout<<dict[i].length()<<endl;
            for (int j = 0; j < dict[i].length(); j++){
                for (int k = 0; k < res.size(); k++) {
                  cout<<"fff"<<endl;
                    temp.push_back(res[k]+dict[i][j]);
                }
              }
            res = temp;
        }
        cout<<res.size();
        // return res;
    }


int main ()
{
  int a[] = {1,1,1,0,2,4,2,5,6,7,2,2,3,3,2,1,2};
  std::vector<int> v(a, a+17);
	return 0;
}
