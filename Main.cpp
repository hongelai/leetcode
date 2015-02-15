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

double median(int arr[], int n){
  if (n % 2 == 0)
  {
    return ((double)arr[n/2 - 1]  + arr[n/2]) / 2;
  } else {
    return arr[n/2];
  }
}
double findMedian(int A[], int m, int B[], int n){
  cout<<m <<"-"<<A[0]<<" "<<n<<"-"<<B[0]<<endl;
  if (m == 0) return median(B, n);
  if (n == 0) return median(A, m);
  if (m == 1 && n == 1) return ((double)A[0] + B[0]) / 2;
  if (A[m/2 - 1] > B[n/2 - 1])
  {
    return findMedian(A, m - m/2, B+n/2, n - n/2);
  } else {
    return findMedian(A+m/2, m - m/2, B, n - n/2);
  }
}


int main ()
{
	int A[] = {1,3,7,13,23};
  int B[] = {2,7,8,33,44,55};
  int m = 0, n = 2;
  int x= 0;
  int y = x&(x-1);
  cout<<y<<endl;
	return 0;
}
