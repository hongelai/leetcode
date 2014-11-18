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
#include <queue>
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

    void sortColors(int A[], int n) {
        int front = 0,back = n-1;
        for(int i =0; i <=back && i >= front;){
            if(A[i]==0){
                if(A[front] == 0){
                   front++; 
                   i++;
                   continue;
                } 
                else swap(A[i],A[front++]);
                if(i == front || (A[i]!= 0 && A[i]!= 2)) i++;
            }else if(A[i]==2){
                if(A[back] == 2){
                    back--;
                    
                    continue;
                } 
                else swap(A[i],A[back--]);
                if(i == back || (A[i] != 0 && A[i]!= 2)) i++;
            }else  i++;
            for(int i=0;i<n;i++) cout<<A[i]<<" ";
            cout<<endl;
        }
        
    }
int main ()
{

	int a[]={-3,-2,-44,-32};
	vector<int> v(a,a+4);
    int b[]={0,2,1};
    sortColors(b,3);

	system("pause");


	return 0;
}
