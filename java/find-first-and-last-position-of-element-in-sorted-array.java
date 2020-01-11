class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] range = {-1 , -1};
        if (nums == null && nums.length == 0) return range;
        
        int s = 0, e = nums.length - 1;
        int l = findInsert(nums, target, true);
        
        if (l == nums.length || nums[l] != target) return range;
        
        range[0] = l;
        range[1] = findInsert(nums, target, false) - 1;
        
        return range;
    }
    
    private int findInsert(int[] nums, int target, boolean first) {
        int start = 0;
        int end = nums.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target || (first && target == nums[mid])) { 
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        return start;
    }
}