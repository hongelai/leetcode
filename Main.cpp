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
#include <regex>
using namespace std;

bool isNumber(const char *s) {
        //regex e("(\\s)*[+-]?((\\.[0-9]+)|([0-9]+\\.[0-9]?)([eE][+-]?[0-9]+)?(\\s)*");
        regex e("(\\s*)[+-]?((\\.[0-9]+)|([0-9]+(\\.[0-9]*)?))(e[+-]?[0-9]+)?(\\s*)");
        if(regex_match("2e10",e))
            return true;
        else return false;
    }
int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) return 0;
        int profit = 0; // 差价，也就是利润
        int cur_min = prices[0]; // 当前最小
        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - cur_min);
            cur_min = min(cur_min, prices[i]);
        }
    return profit;
}
int main ()
{

	int array[]={3,1,2,3,4,5,1,2,10,3};
	vector<int> v(array,array+10);

    cout<<maxProfit(v)<<endl;
	system("pause");

	return 0;
}
