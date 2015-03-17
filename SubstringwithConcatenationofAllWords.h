   //bruteforce
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        int size = L.size();
        int len = S.length();
        int wordLen, start = 0, winSize;
        unordered_map<string, int> map;
        unordered_map<string, int> winMap;
        
        if (size == 0) return ret;
        else {
            wordLen = L[0].length();
            winSize = wordLen*size;
        }
        if (winSize > len) return ret;
        for (int i = 0; i < size; i++) map[L[i]]++;
        
        while (start + winSize <= len) {
            int index = 0;
            string winStr = S.substr(start, winSize);
            while (index + wordLen <= winSize) {
                string sub = winStr.substr(index, wordLen);
                if (map.count(sub) == 0) {
                    break;
                } else {
                    winMap[sub]++;
                    if(winMap[sub] > map[sub]) break;
                    index += wordLen;
                }
            }
            if (index == winSize)  ret.push_back(start);
            start++;
            winMap.clear();
        }
        return ret;
    }