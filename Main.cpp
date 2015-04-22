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
#include <utility> 
using namespace std;

void replaceSpace(string &s, int length){
  int spaceCount = 0;
  for (int i = 0; i < length; ++i)
  {
    if (s[i] == ' ') spaceCount++;
  }
  int newLength = spaceCount*2 + length;
  for (int i = length-1; i >= 0; i--)
  {
    if (s[i] == ' ')
    {
      s[newLength-1] = '0';
      s[newLength-2] = '2';
      s[newLength-3] = '%';
      newLength -= 3;
    } else {
      s[newLength-1] = s[i];
      newLength--;
    }
  }
  cout<<s<<endl;
}
int main ()
{
  int a[] = {1,1,1,1,2,3,3,4,4,5,5,5,5,6,6,6,6,7,9,9,9,9,9,9,9,9};
  vector<int> v(a,a+26);
  string s = "i have a dream            ";
  replaceSpace(s, 14);
	return 0;
}
