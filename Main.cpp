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

    int threeSumClosest(vector<int> &num, int target) {
        int size = num.size();
        int minGap = INT_MAX, ret;
        
        sort(num.begin(), num.end());
        for (int i = 0; i < size-2; i++) {
            int start = i + 1, end = size-1;
            //0 1 1 1 -100
            while (start < end) {
                int sum = num[i] + num[start] + num[end];
                int gap = abs(sum - target);
                if (gap < minGap) {
                    ret = num[i] + num[start] + num[end];
                    cout<<ret<<endl;
                }
                if (sum > target) end--;
                else if (sum < target) start++;
                else return ret;
                
                // while (start < end && num[start-1] == num[start]) start++;
                // while (start <end && num[end+1] == num[end]) end--;
            }
        }

        return ret;
    }
int main ()
{
  int a[] = {1,1,1,0};
  std::vector<int> v(a, a+4);

  threeSumClosest(v, -100);
	return 0;
}
