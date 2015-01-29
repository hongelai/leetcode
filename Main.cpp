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
#include <string>
#include <queue>

using namespace std;

void findFirstUnique(vector<int> &v){

	unordered_map<int,int> map;
	for(int i = 0; i < v.size(); i++){
		if(map.find(v[i]) == map.end()){
			// um.insert(make_pair(a,1)); // cannot use insert again(duplicate), because !um[v[i]] will innitialize it as 0.
			map[v[i]] = 1;
		}
		else map[v[i]]++;
	}
	for(auto it = v.begin();it != v.end(); it++) 
		if(map[*it] == 1) cout<<*it<<" ";

}

vector<int> subtraction(vector<int> a, vector<int> b){
	vector<int> res;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int sa = a.size(), sb = b.size();
	int size  = sa > sb ? sa : sb;
	int borrow = 0;
	for(int i = 0; i < size; i++){
		int digitA = i >= sa ? 0 : a[i];
		int digitB = i >= sb ? 0 : b[i]; 
		int remain = digitA - borrow - digitB;
		if(remain < 0){
			remain = 10 + remain;
			borrow = 1;
		}else{
			borrow = 0;
		} 
		res.push_back(remain);
	}

	if(borrow){
		cout<<'-';
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		return subtraction(b,a);
	}
	reverse(res.begin(),res.end());

	return res;
}
string countAndSay(int n) {
	 string res = "1";

	 while(--n){
	 	string tmp = "";
	 	int len = res.length();
	 	for(int i = 0; i < len;){
	 		int j = i+1;
	 		while(j < len && res[j] == res[j-1]) j++;
	 		tmp.push_back(j-i + '0');
	 		tmp.push_back(res[i]);
	 		i = j;
	 	}
	 	res = tmp;
	 }
	 return res;
}
int main ()
{
	int a[] = {1,1,2,2,3,2,4,5,5,4,6,7,6};
    vector<int> vt(a,a+13) ;

	cout<<countAndSay(5);
	return 0;
}
