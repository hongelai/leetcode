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
int quickSolve(vector<int> prices) {
        int len = prices.size(), profit = 0;
        for (int i = 1; i < len; i++)
            // as long as there is a price gap, we gain a profit.
            if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        return profit;
    }
void maxProfit(int k, vector<int> prices) {
        int len = prices.size();
//        if (k > len / 2) cout<< quickSolve(prices);

        vector<vector<int> > t(k+1, vector<int>(len));
        for (int i = 1; i <= k; i++) {
            int tmpMax = t[i - 1][0] - prices[0];
            for (int j = 1; j < len; j++) {
                t[i][j] = max(t[i][j - 1], prices[j] + tmpMax);
                cout<<t[i][j]<<":"<<tmpMax<<"  ";
                tmpMax =  max(tmpMax, t[i - 1][j - 1] - prices[j]);
                
            }
            cout<<endl;
        }
        cout<< t[k][len - 1]<<endl;
    }

int main ()
{
  int a[] = {2,6,3,5,4,18,1,14,3,55};
  vector<int> v(a,a+10);
  maxProfit(3,v);
	return 0;
}
