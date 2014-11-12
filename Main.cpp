#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <stack>
#include <sstream>
#include <regex>
#include <limits>
using namespace std;
string intToRoman(int num) {
const int radix[] = {1000, 900, 500, 400, 100, 90,
50, 40, 10, 9, 5, 4, 1};
const string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
"L", "XL", "X", "IX", "V", "IV", "I"};
string roman;
for (size_t i = 0; num > 0; ++i) {
int count = num / radix[i];
num %= radix[i];
for (; count > 0; --count) roman += symbol[i];
}
return roman;
}
    int romanToInt(string s) {
        unordered_map<char,int> um;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        int result = 0;
        
        for(auto it = s.begin(); it != s.end();it++){
            char c = *prev(it);
            if(um[*it] > um[c]) result += um[*it] -2*um[c]; // 
            else result += um[*it];
        }
        return result;
    }

int main ()
{

    int array[] = {1,3,2,3,4,5,2,5,1};
    vector<int> v(array,array+9);
    string s="LXXVIII";
//    cout<<romanToInt(s)<<endl;
    cout<<intToRoman(3999)<<endl;
	system("pause");

	return 0;
}
