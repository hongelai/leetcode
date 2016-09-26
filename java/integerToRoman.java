public class Solution {
    public String intToRoman(int num) {
        //左加只能一位，所以下面这个组合能组成任何数字
        int[] value = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        StringBuilder ret = new StringBuilder();
        
        for (int i = 0; i < value.length; i++) {
            int count = num / value[i];
            num %= value[i];
            
            while (count-- > 0) ret.append(symbol[i]);
        }
        return ret.toString();
    }
}