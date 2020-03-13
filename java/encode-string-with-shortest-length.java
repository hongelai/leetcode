class Solution {
    public String encode(String s) {
        //the shortest encode string from i to j
        String[][] dp = new String[s.length()][s.length()];
        
        for (int i = 0; i < s.length(); i++) dp[i][i] = Character.toString(s.charAt(i));
        
        for (int len = 1; len <= s.length(); len++) {        //length of substring
            for (int i = 0; i + len - 1 < s.length(); i++) { //start index of substring
                int j = i + len - 1;                         //end index of substring
                String sub = s.substring(i, i+len);
                dp[i][j] = sub;                              //init with not encode value
                
                //if len < 4, encoding will not help, len("4[a]") == len("aaaa")
                if (len >= 4) {
                    //loop through existing sub-results and try to combine 2
                    for (int k = i; k < j; k++) {
                        if (dp[i][k].length() + dp[k+1][j].length() < dp[i][j].length()) {
                            dp[i][j] = dp[i][k] + dp[k+1][j];
                        }
                    }
                    
                    //try to encode the original substring and see if we can get better result
                    String collapse = tryCollapse(dp, sub, i);
                    if (dp[i][j].length() > collapse.length()) {
                        dp[i][j] = collapse;
                    }
                }
            }
        }
        return dp[0][s.length()-1];
    }
    
    private String tryCollapse(String[][] dp, String s, int i) {
        int pos = (s+s).indexOf(s, 1);
        if (pos >= s.length()) return s;
        return String.valueOf(s.length()/pos) + '[' + dp[i][i + pos - 1] + ']';
    }
}
