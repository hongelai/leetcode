#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <stack>
#include <sstream>
#include <regex>
#include <limits>
#include <unordered_set>
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
    bool isValid(string s) {
        stack<char> sk;
        for(auto it=s.begin(); it != s.end();it++){
            if(*it == '(' || *it == '{' || *it == '[' )
                sk.push(*it);
            else if(*it == ')' || *it == '}' || *it == ']' ){
                cout<<"call"<<endl;
                if(!sk.empty()){
                
                    if((*it == ')' && sk.top() == '(')||(*it == ']' && sk.top() == '[')||(*it == '}' && sk.top() == '{'))
                        sk.pop();
                    }
                else return false;
            }else return false;
        }
        if(sk.empty()) return true;
        else return false;
    }
int main ()
{

	int a[]={1,9,9};
	vector<int> v(a,a+3);
	string str="]";
    cout<<isValid(str)<<endl;
	system("pause");


	return 0;
}
