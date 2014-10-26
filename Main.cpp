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
    void maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size < 2) return;
        prices.push_back(0);
        int valley = 0,peak = 0;
        vector<int> val;
        int profit =0;
        
        for(int i = 1; i <= size;i++){
            if(prices[i] > prices[i+1] && prices[i] >= prices[i-1]){
                peak = i;
                val.push_back(prices[peak]-prices[valley]);
                
            }else if(prices[i] < prices[i+1] && prices[i] <= prices[i-1] ){
                valley = i;
            }
        }
        make_heap(val.begin(),val.end(),less<int>());

        for(int i =0;i < 2;i++) profit+=val[i];
        cout<<profit<<endl;
    }
int main ()
{

	int array[]={3,1,1,3,4,5,1,2,10,3,2,11,13};
	vector<int> v(array,array+13);

//    auto j=partition(v.begin(),v.end(),bind2nd(less<int>(),4));
//    for(auto i = v.begin();i != v.end() ;i++) cout<<*i<"m ";
    maxProfit(v);
	system("pause");

	return 0;
}
