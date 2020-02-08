class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] range = {-1 , -1};
        if (nums == null || nums.length == 0) return range;
        
        int s = 0, e = nums.length - 1;
        int first = findFirst(nums, target);
        int last = findFirst(nums, target+1) - 1;
        
        if (first == nums.length || nums[first] != target) return range;
        
        return new int[]{first, last};
    }
    
    private int findFirst(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;

        while (start+1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) { 
                end = mid;
            }
            else {
                start = mid;
            }
        }
        
        if (nums[start] >= target) return start;
        else if (nums[end] >= target) return end;
        else return end+1;
    }
}