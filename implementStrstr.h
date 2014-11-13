    int strStr(char *haystack, char *needle) {
        int m = strlen(haystack),n = strlen(needle);
        if(m == 0 && n == 0) return 0;
        if(m == 0) return -1;
        int index = 0;
        
        while(haystack[index] != '\0'){
            int i,j;
            i = index;
            j = 0;
            while(needle[j] != '\0' && haystack[i++] == needle[j]) j++;
            if(needle[j] == '\0') return index;
            else index++;
            if(m - index < n) return -1;
        }
        return -1;
    }