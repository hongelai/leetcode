//和readChars I的区别的就是可以多次调用，如果上一次调用最后从file里面读出来的buffer超过了n，超过的部分不能丢弃，
//要保存下来,在下一次调用的时候放在最开始
//idea: 设立一个 4 char 大小的缓存，每次读出来的放里面，用一个bufferPtr指向区间内的当前赋值为止，用bufferCount标志区间大小
//用一个ptr作为buf的赋值指针，
int bufferPtr = 0, bufferCount = 0; //readChars会被多次调用，得作为全局变量
char buffer[4];
int readChars(char *buf, int n){
	int ptr = 0;
	while (ptr < n) {
		if (bufferPtr == 0)
		{
			bufferCount = read4(buffer);
		}
		if (bufferCount == 0) break; //end of file
		while (ptr < n && bufferPtr < bufferCount) { //copy tempory buffer to buf array
			buf[ptr++] = buffer[bufferPtr++];
		}
		if (bufferPtr >= bufferCount) bufferPtr = 0; //rewind the pointer
	}
	return ptr;
}