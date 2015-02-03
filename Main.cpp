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
    int singleNumber(int A[], int n) {
        //solution one: use count[32] to count the bit occurrence of each bit, find out those bit occurrence cannot be devide by 3
        int W = sizeof(int)*8;
        vector<int> count(W,0);
        int res = 0;
        
        for(int i = 0; i < W; i++)
            for(int j = 0; j < n; j++){
                if((A[j]>>i)&1) count[i]++; //first bit >>0, second bit >>1
            }
        
        for(int k = W-1; k >= 0; k--) res += (count[k]%3) << k;
        return res;
    }
int main ()
{

	int a[] = {0,1,0,1,0,1,99};
    vector<int> vt(a,a+7) ;
    cout<<singleNumber(a,7)<<endl;
    
	return 0;
}
