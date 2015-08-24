// http://javahungry.blogspot.com/2013/06/difference-between-string-stringbuilder.html
int isRotation(String s1, String s2) {
	int len = s1.length();
	if (len == s2.length() && len > 0){
		String ss = s1 + s1;            //use StringBuffer
		return ss.indexOf(s2) != -1 ? 1 : -1; //use KMP to reduce O(m*n) to O(n)
	}
	return -1;
}

//Brian Kernighan’s Algorithm to count how many bits are set, complexity O(log(x)) -- log(x) 是算x的bit的位数
/*
Brian Kernighan’s Algorithm:
Subtraction of 1 from a number toggles all the bits (from right to left) till the rightmost 
set bit(including the righmost set bit). So if we subtract a number by 1 and do bitwise & with 
itself (n & (n-1)), we unset the righmost set bit. If we do n & (n-1) in a loop and count the 
no of times loop executes we get the set bit count. Beauty of the this solution is number of 
times it loops is equal to the number of set bits in a given integer.
*/
int grayCheck(byte term1, byte term2) {
	byte x = (byte)(term1 ^ term2);
	int total = 0;
	while(x != 0){
		x = (byte) (x & (x - 1));
		total++; //improvement: when total > 1 ,use break to stop
	}
	return total == 1 ? 1: 0;
}

String delelteVowels(String string) {
	StringBuffer sb = new StringBuffer();
	String v = "aeiouAEIOU";
	for(int i = 0; i < string.length(); i++){
		if(v.indexOf(string.charAt(i)) > -1) continue;
		sb.append(string.charAt(i));
	}
	return sb.toString();
} 

    void getNext(char * T, int next[], int n){
        int i=0, j=-1;
        next[0]=-1;
        while(i<n){
            while(j>-1&&T[j]!=T[i]) j = next[j];
            i++,j++;
            if(T[j]==T[i]) next[i]=next[j];
            else next[i]=j;
        }
    }
    int strStr_2(char *haystack, char *needle) {
        int sLen = strlen(haystack);
        const int tLen = strlen(needle);
        if (tLen == 0) return 0;
        if(haystack==NULL || needle==NULL || sLen==0) return -1;
        
        int next[tLen+1];
        getNext(needle,next,tLen);
        
        int i=0, j=0;
        while(i<sLen){
            while(j>-1&&needle[j]!=haystack[i]) j = next[j];
            i++,j++;
            if(j==tLen){
                return i - j;
            }
        }
        return -1;
    }