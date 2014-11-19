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


    bool isMatch(const char *s, const char *p) {
        const char* pBackup= NULL, *sBackup = NULL;
        
        while(*s != '\0'){
            if(*s == *p || *p == '.'){
                s++;
                p++;
            }else if(*p == '*'){
                
                while(*p == '*') p++;
                if(*p == '\0') return true;
    
                pBackup = p;
                sBackup = s;
            }else{
                if(pBackup){
                    p = pBackup;
                    s = sBackup;
                    s++;
                }else return false;
            }
        }
        cout<<*p<<endl;
        while(*p == '*') p++;
        if(*s == '\0' && *p == '\0') return true;
        else return false;
    }
int main ()
{


    char a[]="ab";
    char b[]=".*c";
    cout<<isMatch(a,b)<<endl;

	system("pause");


	return 0;
}
