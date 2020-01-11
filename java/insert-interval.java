class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> rs = new ArrayList<>();
        
        if (intervals == null || intervals.length == 0) {
            rs.add(newInterval);
            return rs.toArray(new int[rs.size()][2]);
        }
        

        for (int i = 0; i < intervals.length; i++) {
            if (intervals[i][1] < newInterval[0]) { // new interval is behind
                rs.add(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) { //new interval is before
                rs.add(newInterval);
                newInterval = intervals[i];
            } else { //overlap
                newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
                newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            }
        }
        rs.add(newInterval);
        
        return rs.toArray(new int[rs.size()][2]);
    }
}