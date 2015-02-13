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

    int findKthNumber(int A[], int m, int B[], int n, int k){
//        assert(k <= m+n && k);
        if(m == 0) return B[k-1];
        if(n == 0) return A[k-1];
        if(k == 1) return min(A[0], B[0]);
        int h = k/2;
        int asub = min(m, h);
        int bsub = min(n, h);
        if(A[asub-1] > B[bsub-1]) return findKthNumber(A, m, B+bsub, n-bsub, k-bsub);
        else return findKthNumber(A+asub, m-asub, B, n, k-asub);
    }

int main ()
{
	int A[] = {};
    int B[] = {2,3};
    int m = 0, n = 2;
  	cout<<((double)findKthNumber(A, m, B, n, (m+n)/2) + findKthNumber(A, m, B, n, (m+n)/2 + 1)) / 2<<endl;
	return 0;
}
