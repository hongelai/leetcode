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

bool isAnagram(string a, string b){
	int count[256] = {0};
  for (int i = 0; i < a.length(); ++i) count[a[i]]++;
  for (int i = 0; i < b.length(); ++i) count[b[i]]--;
  for (int i = 0; i < 256; ++i)
  {
    if (count[i] != 0)
    {
      return false;
    }
  }
  return true;
}

int findMaxWindow(string a, string b){
	int len = a.length();
	int start = 0, end = len - 1;
	
	for(int ws = len; ws > 0; ws--)
		for(int i = 0; i + ws - 1 < len; i++){
			string str1 = a.substr(i, ws);
			string str2 = b.substr(i, ws);
			if(isAnagram(str1, str2)) return ws;
		}
	return -1;
}
int maxProfit(int k, vector<int> &prices) {
        int size = (int)prices.size();
        if (k==0||size<2) {
            return 0;
        }
        if (k>size/2) {
            int sum = 0;
            for(int i = 1;i < size;i++){
                if(prices[i] > prices[i-1]){
                    sum += prices[i] - prices[i-1];
                }
            }
            return sum;
        }
        vector<int> buy(k,INT_MIN);
        vector<int> sell(k,0);
        for (int i=0; i<size; i++) {
            for (int j=k-1; j>=0; j--) {
                sell[j]=max(sell[j],buy[j]+prices[i]);
                buy[j]=max(buy[j],(j>0?sell[j-1]:0)-prices[i]);
                cout<<sell[j]<<":"<<buy[j]<<" ";
            }
            cout<<endl;
        }
        return sell[k-1];
    }

int main ()
{
  int a[] = {2,6,5,1,10,9,12,16,13,20,11,33};
  vector<int> v(a,a+12);
  maxProfit(3,v);
	return 0;
}
