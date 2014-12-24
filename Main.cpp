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
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        vector<int> asci(256,-1); //mark the position of character
        int start = 0,end = 0,size = s.length();
        
        while(end < size && start+res < size){
            if(asci[s[end]] == -1){
                asci[s[end++]] = end;
          
            }else{
                res = max(end - start,res);
                cout<<start<<" "<<end<<" "<<s.substr(start,end-1-start)<<endl;
                int old_start = start;
                start = asci[s[end]]+1;
                while(old_start < start){
                    asci[s[old_start++]] = -1;
                }
            }
            
        }
        if(!s.empty())
        res = max(end - start + 1,res);
        return res;
    }
int main ()
{
    int aa[]={2,1,3,2,4,2,5,2,6,2,2,2,3};
    
    vector<int> vc(aa,aa+13);
    cout<<lengthOfLongestSubstring("qopubjguxhxdipfzwswybgfylqvjzhar")<<endl;

	system("pause");


	return 0;
}
