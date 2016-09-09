public class Solution {
    public String convert1(String s, int numRows) {
        // use index to keep track of current row num, use muliple String to record character from each row
        if(numRows<=1)return s;
        StringBuilder strs[] = new StringBuilder[numRows];
        for(int i = 0; i < strs.length ; i++) strs[i] = new StringBuilder("");
        
        int currRow  = 0;
        int increment = 1; //control currRow to go up and down
        
        for (int i = 0; i < s.length(); i++) {
            strs[currRow].append(s.charAt(i));
            if (currRow == 0) increment = 1;
            else if (currRow == numRows -1) increment = -1;
            currRow += increment;
        }
        
        String ret = "";
        for(StringBuilder str : strs) {
            ret += str;
        }
        
        return ret;
    }
    
    public String convert(String s, int numRows) {
        //we need to pick up the character every 2*numRows -1
        if (numRows <= 1) return s;
        StringBuilder ret = new StringBuilder();
        int step = 2 * (numRows -1);
        for (int i = 0; i < numRows; i++)
        {
            for (int x = i; x < s.length(); x += step) {
                ret.append(s.charAt(x));
                int xDiag = x + step - i*2; //index of diag
                if(i > 0 && i < numRows - 1 && xDiag < s.length()) {
                    ret.append(s.charAt(xDiag));
                }
            }
        }
        return ret.toString();
    }
}