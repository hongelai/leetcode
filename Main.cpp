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
    
    bool isPalidrome(string sub){
        int low = 0, high = sub.size()-1;
        while(low < high){
            if(sub[low] == sub[high]){
                low++;
                high--;
            }else break;
        }
        return low >= high;
    }
    void dfs(string str, int start, vector<string> &item, vector<vector<string> > & res){
        int length = 1;
        int oriSize = item.size();
        for(int i = start; i < str.length();){
            string sub = str.substr(start,length);
            item.resize(oriSize);
            
            if(isPalidrome(sub)){
                
                item.push_back(sub);
                if(length == str.length()-i)
                {
                    res.push_back(item);
                    break;
                }
                i += length;
                dfs(str,i,item,res);
            } 
            length++;
            if(length > str.length() - i) break;
            
        }  
    }
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<string> item;
        dfs(s,0,item,res);
        return res;
    }
int main ()
{
    int aa[]={1,1,1,0};
    
    vector<int> vc(aa,aa+4);
    string str = "aab";
    vector<vector<string> > res = partition(str);

    for (int i = 0; i < res.size(); ++i)
    {
        /* code */
        for (int j = 0; j < res[i].size(); ++j)
        {
            /* code */
            cout<<res[i][j]<<"  ";
        }
        cout<<endl;
    }

	// system("pause");


	return 0;
}
