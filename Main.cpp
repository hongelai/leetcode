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
struct comparator
{
  bool operator() (pair<int,int> a, pair<int,int> b){
    if(a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
  }
};


int main ()
{
  int a[] = {1,1,1,1,2,3,3,4,4,5,5,5,5,6,6,6,6,7,9,9,9,9,9,9,9,9};

  vector<int> v(a,a+26);
  topK(v,3);
	return 0;
}
