string longest_repeated_substring(string str) {
    int len = str.length();
    int dp[len][len];
    for (int i = 0; i <= len; ++i) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    int max_len = 0, index = len + 1;
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            //str[i-1] == str[j-1],所以 sub2的起点要大于i 否则就会重叠 abs(i-j)+1 是sub2可能的最长长度 dp[i-1][j-1]+1 是sub1的可能最长长度
            if (str[i-1] == str[j-1] && abs(i-j) > dp[i-1][j-1]) { 
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    index = min(i, j);
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return max_len > 0 ? str.substr(index - max_len, max_len) : "";
}

//Given a string s, find the longest substring that appears more than once in s.
//eg. "abcabcaacb", return "abca" ; "aababa", return "aba"
//suffix array 
string longestCommonPrefix(string s1, string s2) {
    string s = "";
    int size = min(s1.length(), s2.length());
    if (size == 0) return s;
    for (int i = 0; i < size; i++) {
        if (s1[i] != s2[i]) return s1.substr(0, i); 
    }
    return s1.substr(0, size);
}

string longestRepeatedSubstring(string s){
    vector<string> sub; //suffix array
    int len = s.length();
    for (int i = 0; i < len; i++) {
        string str = s.substr(i, len-i);
        sub.push_back(str);
    }
    sort(sub.begin(), sub.end());

    string ret = "";
    for (int i = 0; i < len - 1; ++i)
    {
        string x = longestCommonPrefix(sub[i], sub[i+1]);
        if (x.length() > ret.length())
        {
            ret = x;
        }
    }
    return ret;
}