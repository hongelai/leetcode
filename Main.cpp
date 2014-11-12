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
#include <limits>
using namespace std;
class MinStack {
public:
    void push(int x) {
        if(s.empty()){
          
            min = x;
        }
        s.push(x - min);
        if(x < min) min = (long long)x;  // replace min after the push the min, so only whenever negative means min change
    }

    void pop() {
        if(!s.empty()){
            if(s.top() < 0) min = min - s.top();
            s.pop();
        }
    }

    int top() {
        if(s.top() < 0) return (int)min; // at turning point the min is itself
        else            return (int)(s.top()+min);
    }

    int getMin() {
        return (int)min;
    }
    stack<long long> s;
    long long min;
};
int main ()
{

    int array[] = {1,3,2,3,4,5,2,5,1};
    vector<int> v(array,array+9);
    MinStack ms;
    ms.push(2147483646);
    ms.push(2147483646);
    ms.push(2147483647);  
    cout<<ms.top()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;  
    ms.pop();
    cout<<ms.getMin()<<endl;
    ms.pop();
    ms.push(2147483647);
    cout<<ms.top()<<endl;
    cout<<ms.getMin()<<endl;
    ms.push(-5);    
    cout<<ms.top()<<endl;
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;  
    
 
	system("pause");

	return 0;
}
