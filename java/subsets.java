class Solution {
    List<List<Integer>> rs;
        
    public List<List<Integer>> subsets(int[] nums) {
        rs = new LinkedList<List<Integer>>();
        
        Arrays.sort(nums);
        rs.add(new LinkedList<Integer>());
        backTracking(nums, 0, new LinkedList<Integer>());
        
        return rs;
    }
    
    private void backTracking(int[] nums, int index, LinkedList<Integer> item) {
        if (index >= nums.length) return;
        
        for (int i = index; i < nums.length; i++) {
            item.add(nums[i]);
            rs.add(new LinkedList<Integer>(item));
            backTracking(nums, i+1, item);
            item.removeLast();
        }
    }
    
    public List<List<Integer>> subsets_1(int[] nums) {
        rs = new ArrayList<List<Integer>>();
        rs.add(new ArrayList<Integer>());
        
        for (int i = 0; i < nums.length; i++) {
            int size = rs.size();
            for (int j = 0; j < size; j++) {
                ArrayList<Integer> item = new ArrayList<>(rs.get(j));
                item.add(nums[i]);
                rs.add(item);
            }
        }
        
        return rs;
    }
}