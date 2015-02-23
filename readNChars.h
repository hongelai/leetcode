//读的char可能会少于n 或者 超过n
int read(char *buf, int n) 
    {
        int num = 0, cnt;
        while(num < n && (cnt = read4(buf+cnt))) 
        {
            num += cnt;
        }
        if(num >= n) //
        {
            buf[n-num] = '\0';
            num = n;
        }
        return num;
    }