public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ret = new ArrayList<String>();
        generate(ret, n, n, "");
        return ret;
    }
    
    public void generate(List<String> ret, int left, int right, String item) {
        if (left == 0 && right == 0) {
            ret.add(item);
            return;
        }
        
        if (left > 0) {
            generate(ret, left-1, right, item + "(");
        }
        if (left < right) {
            generate(ret, left, right-1, item + ")");
        }
    }
}