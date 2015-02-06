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
    int trap(int A[], int n) {
        int maxCur = 0;
        int maxNext = 0;
        int res = 0;
        int size = n + 2;
        vector<int> B(n+2,0);
        for(int i = 1; i <= n; i++) B[i] = A[i-1];
        
        for(int i = 1; i <= n;){
            for(int j = i; j <= n; j++){ // find peak
                if(B[j] >= B[j-1] && B[j] > B[j+1]){
                    if(B[maxCur] == 0){
                        maxCur = j;
                    }else{
                        maxNext = j;
                        break;
                    }
                }
            }
            if(maxCur != maxNext && maxCur != 0 && maxNext != 0){
                int high = min(B[maxCur], B[maxNext]);
                for(int k = maxCur + 1; k < maxNext; k++){
                    res += high - B[k];
                }
                i = maxNext+1;
                maxCur = maxNext;
            }else{
                i++;
            }
            
        }
        return res;
    }
int main ()
{
	int a[] = {5,4,1,2};
    vector<int> vt(a,a+13) ;
    cout<<trap(a,4)<<endl;
	return 0;
}
