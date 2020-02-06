class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int count = 0, start = 0, end = 0, res = 0;
        int[] dict = new int[256];
        
        while (end < s.length()) {
            int ec = (int) s.charAt(end++);
            dict[ec]++;
            
            if (dict[ec] == 1) count++;
            while (count > 2) {   
                int sc = (int) s.charAt(start++);
                dict[sc]--;
                if (dict[sc] == 0) count--;
            }
            
            res = Math.max(res, end-start);
        }
        
        return res;
    }
}