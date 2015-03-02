    vector<int> findSubstring(string S, vector<string> &L) {
        int len = S.length(), size = L.size();
        vector<int> ret;
        if(len == 0 || size == 0) return ret;
        int wordLen = L[0].length(), count = 0;
        unordered_map<string, int> need;
        unordered_map<string, int> find;
        
        for(int i = 0; i < size; i++){
            need[L[i]]++;
        }
        for (int i = 0; i < wordLen; i++) {
            find.clear();
            count = 0;
            for (int start = i, end = i; end + wordLen <= len; end += wordLen) {
                string sub = S.substr(end, wordLen);
                if (need.count(sub) == 0) {
                    start = end + wordLen;
                    find.clear();
                    count = 0;
                    continue;
                }
                while(find.count(sub) != 0 && find[sub] >= need[sub]){ //从start开始删除word，直到count(sub) == need-1
                    string startStr = S.substr(start, wordLen);
                    start += wordLen;
                    find[startStr]--;
                    count--;
                }
                //添加sub
                find[sub]++;
                count++;
                if(count == size) ret.push_back(start);
                
            }
        }
        return ret;
        
    }

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
            if (index == winSize) {
                ret.push_back(start);
                // start += winSize;
            } else {
                // start += index + wordLen;
            } 
            start++;
            winMap.clear();
        }
        return ret;
    }