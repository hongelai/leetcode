class Solution {
    List<List<Integer>> rs;
    int[] nums;
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        this.rs = new ArrayList<List<Integer>>();
        this.nums = nums;
        
        Arrays.sort(nums);
        
        rs.add(new ArrayList<Integer>());
        int preIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            int size = rs.size();
            
            for (int j = 0; j < size; j++) {
                if(i== 0 || nums[i] != nums[i-1] || j >= preIndex){
                    List<Integer> item = new ArrayList<>(rs.get(j));
                    item.add(nums[i]);
                    rs.add(item);
                }
            }
            preIndex = size;
            
        }
        
        return rs;
    }
    
    public List<List<Integer>> subsetsWithDup_1(int[] nums) {
        this.rs = new ArrayList<List<Integer>>();
        this.nums = nums;
        
        Arrays.sort(nums);
        
        backTracking(new ArrayList<Integer>(), 0);
        
        return rs;
    }
    
    
    private void backTracking(List<Integer> item, int index) {
        rs.add(new ArrayList<Integer>(item));
        
        for (int i = index; i < nums.length; i++) {
            if (i != index && nums[i] == nums[i-1]) continue;
            item.add(nums[i]);
            backTracking(item, i+1);
            item.remove(item.size() - 1);
        }
    }
}