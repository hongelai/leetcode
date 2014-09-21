// queue::push/pop
#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
int main ()
{
	string  S= "barfoothefoobarman";
	vector<string> L;
	L.push_back("foo");
	L.push_back("bar");
	typedef unordered_map<string, int> umap;
	umap um;
	um(make_pair("abc",23));
	um(make_pair("abc",22));
	umap::const_iterator cit;
	
	// vector<int> result = findSubstring(S,L);
	// while(!result.empty()){
	// 	cout<<result.back()<<endl;
	// 	result.pop_back();
	// } 

	system("pause");
	return 0;
}
