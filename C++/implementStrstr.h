    int strStr(char *haystack, char *needle) {
        int m = strlen(haystack), n = strlen(needle);
        if (m == 0 && n == 0) return 0;
        if (m == 0) return -1;
        if (n == 0) return 0;
        int index = 0;
        
        while(index < m && index + n <= m) {
            int i = index, j = 0;
            while (needle[j] != '\0' && haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == n) return index;
            else index++;
        }
        return -1;
    }