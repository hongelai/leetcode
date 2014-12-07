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
    string minWindow(string S, string T) {
        int M = S.size(),N = T.size();
        if(M < N) return "";
        int need[256] = {0}, find[256] = {0};
        
        int start, end,rstart = -1,rend = M,count=0;
        start = end = 0;
        
        for(int i = 0; i < N; i++) need[T[i]]++;

        for(int i = 0; i < M; i++,end++){
            if(!need[S[i]]) continue;
            
            find[S[i]]++;
            if(find[S[i]] <= need[S[i]]) count++;
            if(count == N){ //find all needed characters
                for(;start <= end; start++){
                    if(!find[S[start]]) continue;
                    if(find[S[start]] <= need[S[start]]) break;
                    find[S[start]]--;
                }
                //update rstart , rend
                if(end- start < rend - rstart){
                    rstart = start;
                    rend = end;
                }
            }
            
             
        }
        cout<<rstart<<" "<<rend<<endl;
        return rstart == -1? "":string(S.begin()+rstart,S.begin()+rend+1);
    }

int main ()
{
    int aa[]={1,1,1,0};
    
    vector<int> vc(aa,aa+4);
    int a = 1 <<2 -1;
    cout<<a<<endl;

	system("pause");


	return 0;
}
