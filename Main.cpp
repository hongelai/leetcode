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
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;



int main ()
{
	int array[]={100,4,200,1,3,2};
	vector<int> num(array,array+6);


	cout<<longestConsecutive(num)<<endl;

	return 0;
}
