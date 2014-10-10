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
#include <stack>
#include "LargestRectangleinHistogram.h"
using namespace std;


int main ()
{
	int array[]={2,1,5,6,2,3};
	vector<int> num(array,array+6);
	
	cout<<largestRectangleArea(num)<<endl;


	return 0;
}
