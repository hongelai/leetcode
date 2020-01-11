class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        int L  = maxWidth;
        List<String> rs = new ArrayList<>();
        char[] spaces = new char[maxWidth];
        Arrays.fill(spaces, ' ');
        
        for (int i = 0; i < words.length;) {
            int j = i, len = 0;
            StringBuilder line = new StringBuilder();
            
            while (j < words.length) {
                int wLen = words[j].length();
                if (len + wLen + j - i <= L) {
                    j++;
                    len += wLen;
                } else {
                    break;
                }
            }
            
            if (j < words.length) { // not the last line
                int sCount = L - len;
                for (int k = i; k < j; k++) {
                    line.append(appendSpace(words[k], spaces, k - i, sCount, j - i));
                }
            } else { // last line
                
                for (int k = i; k < j; k++) {
                    if (k != i) {
                        line.append(" ");
                    }
                    line.append(words[k]);
                    if (k+1 == j && line.length() < L) {
                        line.append(spaces, 0, L - line.length());
                    }
                }
            }
            rs.add(line.toString());
            i = j;
        }
        return rs;
    }
    
    private String appendSpace(String word, char[] spaces, int index, int sCount, int wCount) {
        StringBuilder str = new StringBuilder(word);
        
        if (wCount == 1) {// only one word
            str.append(spaces, 0, sCount);
            return str.toString(); 
        }
        if (index + 1 == wCount) return str.toString(); // last word
        
        int remain = sCount%(wCount - 1);
        
        int space = index < remain ? sCount/(wCount - 1) + 1 : sCount/(wCount - 1);
        str.append(spaces, 0, space);
        return str.toString();
    }
}