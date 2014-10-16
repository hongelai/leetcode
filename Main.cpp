// queue::push/pop
#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <sstream>

using namespace std;

int main ()
{

	int a[]={1,3,4,33,11,22,33,42,12,1};
    vector<int> v(a,a+10);
    function<bool(int,int)> less_than = [](int a,int b){return a<b;};
    cout<<count_if(v.begin(),v.end(),bind1st(less_than,20))<<endl;

	system("pause");

	return 0;
}
