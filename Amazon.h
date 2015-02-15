bool isRotation(String s1, String s2) {
	int len = s1.length();
	if (len == s2.length() && len > 0){
		String ss1 = s1 + s1;
		return ss1.indexOf(s2) != -1 ? 1 : -1;
	}
	return -1;
}

bool grayCode(byte term1, byte term2) {
	byte x = (byte)(term1 ^ term2);.
	int total = 0;
	while(x != 0){
		x = (byte) (x & (x - 1));
		total++;
	}
	if(total == 1) return 1; else return 0;
}

String delelteVowels(String string) {
	StringBuffer sb = new StringBuffer();
	String v = "aeiouAEIOU";
	for(int i = 0; i < string.length(); i++){
		if(v.indexOf(string.charAt(i)) > -1) continue;
		sb.append(string.charAt(i));
	}
	return sb.toStirng();
}