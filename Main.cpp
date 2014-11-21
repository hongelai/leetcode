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
    int threeSumClosest(vector<int> &num, int target) {
        int res, gap = 10000, size = num.size();
        sort(num.begin(),num.end());
        for(int i = 0; i < size-2; i++){
            int pre = i+1,last = size-1;
            
            while(pre < last){
                
                if(abs(num[i]+num[pre]+num[last]-target) < gap ){
                    gap = abs(num[i]+num[pre]+num[last]-target);
                    res = num[i]+num[pre]+num[last];
                    if(res > target) last--;
                    else if(res < target)pre++;
                    else return res;
                }else{
                    if(num[i]+num[pre]+num[last] < target) pre++;
                    else last--;
                   
                }
            }
        }
        return res;
    }
int main ()
{
    int aa[]={1,1,1,0};
    
    vector<int> vc(aa,aa+4);

    cout<<threeSumClosest(vc,100);
	system("pause");


	return 0;
}
