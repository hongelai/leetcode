 public int read(char[] buf, int n) {
 	char[] buf4 = new char[4];
 	int charRead = 0
 	boolean eof = false;

 	while (!eof && charRead < n) {
 		int size = read4(buf4);
 		if (size < 4) {
 			eof = true;
 		}
 		
 		System.arrayCopy(buf4, 0, buf, charRead, size);
 		charRead += size;
 	} 
 	return charRead;
 }