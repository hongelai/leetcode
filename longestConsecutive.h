int longestConsecutive(vector<int> &num) {

	int result = 0;
	unordered_set<int> uset;
	for (int i = 0; i < num.size(); ++i)
		uset.insert(num[i]);
	for (int i = 0; i < num.size() && !uset.empty();  ++i)
	{
		if (uset.find(num[i]) == uset.end())
			continue;
		int upper,lower;
		upper = lower = num[i];
		while(uset.find(upper+1)!=uset.end())
			uset.erase(++upper);
		while(uset.find(lower-1)!=uset.end())
			uset.erase(--lower);
		uset.erase(num[i]);

		result = max(result, upper-lower+1);
	}
	return result;
}

    int longestConsecutive(vector<int> &num) {
        unordered_map<int ,bool> map;
        int size = num.size(), ret = 0;
        if (size <= 1) return size;
        for (int i = 0; i < size; i++) map[num[i]] = false;
        for (int i = 0; i < size; i++){
            int left = 0, right = 0, tmp = num[i];
            while(map.count(tmp-1) != 0 && map[tmp-1] == false) {
                left++;
                map[--tmp] = true;
            }
            tmp = num[i];
            while(map.count(tmp+1) != 0 && map[tmp+1] == false) {
                right++;
                map[++tmp] = true;
            }
            ret = max(ret, left+right+1);
        }
        return ret;
    }