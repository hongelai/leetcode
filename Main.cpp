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
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	return a == b;
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
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        int result = 0;
        vector<int> height(col+1,0);
        
        for(int i = 0; i < row; i++){//generate a histogram each row
            stack<int> st;
            for(int j = 0; j < col; j++){
                height[j] = matrix[i][j]  == '1' ? height[j] + 1 : 0;
            }
            for(int k = 0; k <= col;){

                if(st.empty() || height[k] >= height[st.top()]) st.push(k++);
                else{
                    int tmp = st.top();
                    cout<<height[tmp]<<endl;
                    st.pop();
                    result = max(result,height[tmp]*(st.empty()? k: k-st.top()-1));
                }
            }
        }
        return result;
    }
int main ()
{
	int a[] = {5,4,1,2};
  vector<int> vt(a,a+13) ;
  vector<vector<char> > m(1,vector<char>(1,'1'));
  cout<<maximalRectangle(m)<<endl;
	return 0;
}
