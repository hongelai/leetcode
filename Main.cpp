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

    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        if(num.size() < 3) return res;
        sort(num.begin(),num.end());
        int target = 0;
        
        for(int i = 0; i < num.size()-2; i++){
             if(num[i] == num[i-1]) continue;
            
            int pre = i+1, last = num.size()-1;

            while(pre < last){
                if(num[i]+num[pre]+num[last] > target){
                    last--;
                }else if(num[i]+num[pre]+num[last] < target){
                    pre++;
                }else{
                    res.push_back({num[i],num[pre],num[last]});
                    last--; //在当前范围内继续缩小寻找
                    pre++;
                }
            }
            
        }
//        sort(res.begin(),res.end());
        for(int i = 0; i < res.size(); i++){
            for(int j = 0; j < res[0].size();j++)
             cout<<res[i][j]<<" ";
             cout<<endl;
         }          
        res.erase(unique(res.begin(), res.end()), res.end());
              
        return res;
    }

int main ()
{
    int aa[]={-1, 0, 1, 2, -1, -4};
    vector<int> vc(aa,aa+6);
    vector<vector<int> > res;
    res.push_back({2,1,3});
    res.push_back({1,2,3});
    res.push_back({2,3,1});
    res.push_back({1,3,2});
    res.push_back({3,2,3});
    res.push_back({3,3,2});
    
    sort(res.begin(),res.end());
            for(int i = 0; i < res.size(); i++){
            for(int j = 0; j < res[0].size();j++)
             cout<<res[i][j]<<" ";
             cout<<endl;
         }  
         res.erase(unique(res.begin(), res.end()), res.end());
         cout<<endl;
                 for(int i = 0; i < res.size(); i++){
            for(int j = 0; j < res[0].size();j++)
             cout<<res[i][j]<<" ";
             cout<<endl;
         }      
//    threeSum(vc);
	system("pause");


	return 0;
}
