public class Solution {
    public int strStr(String haystack, String needle) {
        if (haystack == null || needle == null) return -1;
        int M = haystack.length(), N = needle.length();
        if (N == 0) return 0;
        if (M < N || M == 0) return -1;
        
        int index = 0;
        while (M - index >= N) {
            int i = index, j = 0;
            while (j< N && haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
            }
            if (j == N) return index;
            else index++;
        }
        return -1;
    }
}