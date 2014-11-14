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