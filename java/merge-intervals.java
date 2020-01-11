class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0) return new int[0][0];
        List<Interval> inters = new ArrayList<>();
        List<Interval> rs = new ArrayList<>();
        
        for (int i = 0; i < intervals.length; i++) {
            inters.add(new Interval(intervals[i][0], intervals[i][1]));
        }
        
        Collections.sort(inters, (o1, o2) -> {return o1.start - o2.start;});
        
        int start = inters.get(0).start, end = inters.get(0).end;
        for (Interval i : inters) {
            if (end >= i.start) {
                end = Math.max(end, i.end);
            }
            else {
                rs.add(new Interval(start, end));
                start = i.start;
                end = i.end;
            }
        }
        rs.add(new Interval(start, end));
        
        int[][] ret = new int[rs.size()][2];
        for (int i = 0; i < rs.size(); i++) {
            ret[i][0] = rs.get(i).start;
            ret[i][1] = rs.get(i).end;
        }
        
        return ret;
    }
    
    class Interval{
        int start;
        int end;
        Interval(int s, int e) {
            this.start = s;
            this.end = e;
        }
    }
}