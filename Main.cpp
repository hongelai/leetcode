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

#define SIZE 7
class SetStack
{
    private:
        int capacity;
        int index;
        vector<stack<int> > sk;
    public:
        SetStack(int capa = SIZE){
            capacity = capa;
            index = 0;
            sk.push_back(stack<int>());
        }
        
        ~SetStack(){
          sk.clear();
        }

        void push(int d) {
          stack<int> tmp = sk[index];
          if (tmp.size() == capacity)
          {

            sk.push_back(stack<int>());
            index++;
          }

          sk[index].push(d);
        }

        void pop(){
          stack<int> tmp = sk[index];
          if(tmp.size() == 0 && index > 0){
            sk.erase(sk.begin() + index);
            index--;
          }
          
          sk[index].pop();
          
        }

        int top(){
          if (sk[index].size() == 0 && index > 0)
          {
            sk.erase(sk.begin() + index);
            index--;
          }
          return sk[index].top();
        }
        
        bool empty() {
          if (index == 0 && sk[index].size() == 0)
          {
            return true;
          } else {
            return false;
          }
        }
};
int main ()
{
  int a[] = {1,4,5,7,10,12,33,35};

   SetStack ss;
    for(int i=0; i<27; ++i){
        ss.push(i);
    }
    cout<<ss.getSize()<<endl;
    while(!ss.empty()){
        cout<<ss.top()<<endl;
        ss.pop();
    }
	return 0;
}
