bool isRotation(String s1, String s2) {
	int len = s1.length();
	if (len == s2.length() && len > 0){
		String ss1 = s1 + s1;
		return isSubstring(ss1, s2);// ss1.indexOf(s2) != -1;
	}
	return false;
}

bool grayCode(byte term1, byte term2) {
	byte x = (byte)(term1 ^ term2);
	int count = 0;

	while(x != 0) {
		total++;
		x = (byte)(x & (x-1));
	}
	if (total == 1) return true;
	else return false;
}

String remove(String string) {
	StringBuilder sb = new StringBuilder();
	String v = "aeiouAEIOU";

	for (int i = 0; i < string.length(); i++) {
		if(v.indexOf(string.charAt(i)) > -1) continue;
		else sb.append(string.charAt(i));
	}
	return sb;
}