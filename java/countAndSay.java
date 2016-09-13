public class Solution {
    public String countAndSay(int n) {
        StringBuilder str = new StringBuilder("1");
        
        while(--n > 0){
            StringBuilder tmp = new StringBuilder();
            for (int i = 0; i < str.length();) {
                int j = i+1;
                while (j < str.length() && str.charAt(j) == str.charAt(j-1)) j++;
                tmp.append(j-i);
                tmp.append(str.charAt(i));
                i = j;
            }
            str = tmp;
        }
        return str.toString();
    }
}