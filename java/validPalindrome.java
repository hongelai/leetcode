public class Solution {
    public boolean isPalindrome(String s) {
        if (s == null) return true;
        s = s.toLowerCase();
        int low = 0, high = s.length()-1;
        while (low < high) {
            while (!Character.isLetterOrDigit(s.charAt(low)) && low < high) low++;
            while (!Character.isLetterOrDigit(s.charAt(high)) && low < high) high--;
            if (s.charAt(low) != s.charAt(high)) return false;
            low++;
            high--;
        }
        return true;
    }
}