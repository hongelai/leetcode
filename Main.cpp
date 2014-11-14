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
//#include <limits>
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
string addBinary(string a, string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int len1 = a.length();
    int len2 = b.length();
    int length = max(len1,len2);
    string res="";
    int carry =0,index = 0;
    
    while(index < length){

        int val=0;
        if(index <len1) 
            val += a[index]-'0';
        if(index < len2)
            val += b[index] -'0' ;
        val += carry;
 
            carry = val/2;
            val = val - carry*2;
     
        res.insert(res.begin(),val+'0');
        index++;
    }
    if(carry > 0) res.insert(res.begin(),carry+'0');

    return res;
}
int main ()
{

	int a[]={1,9,9};
	vector<int> v(a,a+3);
    string a1=    "101";
    string b = "110110";
    cout<<addBinary(a1,b)<<endl;
//      string res;
//      res += 3+'0';
//      cout<<res;
	system("pause");


	return 0;
}
