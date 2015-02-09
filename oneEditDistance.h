bool oneEditDistance(string a, string b){
	if (a.length() > b.length()) swap(a ,b);
	if (b.length() - a.length() > 1) return false;

	bool haveOne = false;
	for (int i = 0，j = 0; i < a.length(); i++, j++) { //
		if (a[i] != b[j]) {
			if (haveOne) {
				return false;
			} else {
				haveOne = true;
				if(a.length() < b.length()) i--; //如果conflict，且 alen < blen,可以跳过 b的一个char
			}
		}
	}

	return haveOne || a.length() < b.length(); // 处理前缀 abc abcd, haveOne = false
}