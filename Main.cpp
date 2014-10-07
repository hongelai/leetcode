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
using namespace std;

	int maxInt(int a , int b){
		return a > b?a:b;
	}

    int largestRectangleArea(vector<int> &height) {
        
        if(height.size() == 0) return 0;
        if(height.size() == 1) return height[0];
        vector<int> sub(height.begin(),height.end()-1);
        int lowest = height.back();
        int max = height.back();
        
        for(auto it = height.end()-2; it > height.begin();it--){
        	if (lowest > *it)
        		lowest = *it;
        	
        	int tempMax = lowest*(height.end()-it);
        	if (tempMax > max)
        		max = tempMax;
        }
        return maxInt(largestRectangleArea(sub),max);
            
        
    }

int main ()
{
	int array[]={2,1,5,6,2,3};
	vector<int> num(array,array+6);
	
	cout<<largestRectangleArea(num)<<endl;

	

	return 0;
}
