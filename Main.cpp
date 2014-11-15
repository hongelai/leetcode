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
//#include <regex>
#include <limits>
#include <unordered_set>
#include <string.h>
using namespace std;

int findFirstUnique(vector<int> &v){

	unordered_map<int,int> um;
	unordered_set<int> us;
	for(int i = 0; i < v.size(); i++){
		if(!um[v[i]]){
			// um.insert(make_pair(a,1)); // cannot use insert again(duplicate), because !um[v[i]] will innitialize it as 0.
			um[v[i]] = 1;
			us.insert(v[i]);
		}
		else{
			um[v[i]]++;
			us.erase(v[i]);
		}
	}
	// for(auto it = um.begin();it!=um.end();it++) cout<<it->first<<" "<<it->second<<endl;
	for(auto it = us.begin();it!=us.end();it++) cout<<*it<<" ";

	return *us.begin();
}
    int firstMissingPositive1(int A[], int n) {
        int i = 0;
        while (i < n)
        {
            if (A[i] != (i+1) && A[i] >= 1 && A[i] <= n && A[A[i]-1] != A[i])
                swap(A[i], A[A[i]-1]);
            else
                i++;
        }
        for (i = 0; i < n; ++i)
            if (A[i] != (i+1))
                return i+1;
        return n+1;
    }
    int firstMissingPositive(int A[], int n) {
        int minInt =numeric_limits<int>::max();
        for(int i =0; i<n;i++){
            if(A[i] >0) minInt = min(minInt,A[i]);
        }
        if(minInt ==numeric_limits<int>::max() ) return 1;
        
        for(int i =0; i<n;i++)
            A[i] =A[i]-minInt+1;
    
        for(int i = 0; i < n; ){
            if(A[i]>0 && A[i]<=n && A[i] != i+1 && A[i]!=A[A[i]-1])
                swap(A[i],A[A[i]-1]);
            else i++;
        }

        for(int i = 0; i < n; i++){
            if(A[i] != i+1) return i+minInt;
        }
        return n+1+minInt;
        

    }
int main ()
{

	int a[]={-3,-2,-44,-32};
	vector<int> v(a,a+4);
 cout<<firstMissingPositive(a,4);
// int* p = new int[1];
// cout<<p[3]<<endl;
	system("pause");


	return 0;
}
