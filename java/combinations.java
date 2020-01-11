class Solution {
    int k;
    int n;
    List<List<Integer>> rs;
    
    public List<List<Integer>> combine(int n, int k) {
        rs = new ArrayList<List<Integer>>();
        this.k = k;
        this.n = n;
        backTracking(new LinkedList<Integer>(), 0);
        
        return rs;
    }
    
    private void backTracking(LinkedList<Integer> item, int index) {
        if (item.size() == 0 && index + k > n) return; //trim
        if (item.size() == k) {
            rs.add(new LinkedList<Integer>(item));
            return;
        }
        
        for (int i = index; i < n; i++) {
            item.add(i+1);
            backTracking(item, i+1);
            item.removeLast();
        }
    }
}