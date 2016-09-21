public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (numRows <= 0) return result;
        result.add(new ArrayList<Integer>(Arrays.asList(1)));
        
        for (int i = 1; i < numRows; i++) {
            List<Integer> pre = result.get(i-1);
            ArrayList<Integer> cur = new ArrayList<Integer>(Arrays.asList(1));
            for (int j = 1; j < pre.size(); j++) {
                cur.add(pre.get(j-1) + pre.get(j));
            }
            cur.add(1);
            result.add(cur);
        }
        return result;
    }
}