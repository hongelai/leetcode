class Solution {
    private Integer min = Integer.MAX_VALUE;
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle.size() == 0) return 0;
        
        for (int i = triangle.size() - 2; i >= 0; i--) {
            List<Integer> row = triangle.get(i);
            for (int j = 0; j < row.size(); j++) {
                int min = Math.min(triangle.get(i+1).get(j),triangle.get(i+1).get(j+1));
                row.set(j, min + row.get(j));
            }
        }
        return triangle.get(0).get(0);
    }
}