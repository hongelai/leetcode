string longestSubstringWithTwoCharacter(string s){
	int set[256]; // store the last occur index of charactor i
	int len = s.length();
	string res = "";
	int start = 0, end = 0, count = 0;
	char charA = -1, charB = -1; // record this unique character

	for(int i = 0; i < 256; i++) set[i] = -1;
	while(end < len){
		
		if(set[s[end]] == -1){ // if is a new charactor between [start,end]
			count++;
			if(count <= 2){
				if (charA == -1) charA = s[end];
				else charB = s[end];
			}else{ // a,b,a,a,a,a,a,a,a,c,a,a,a,a,a,
				int nextIndex;
				if (set[charA] > set[charB])
				{
					nextIndex = set[charB] + 1;
					set[charB] = -1;
					charB = s[end];
				}else{
					nextIndex = set[charA] + 1;
					set[charA] = -1;
					charA = s[end];
				}
				start = nextIndex;
				count--;
			}
			
		}
		if(res.length() <= end - start + 1) res = s.substr(start,end - start + 1);
		set[s[end]] = end;
		end++;
	}
	return res;
}