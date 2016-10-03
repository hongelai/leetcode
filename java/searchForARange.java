public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int lower = findLowerBound(nums, target);
        int uper = findUperBound(nums, target);
        if (lower <= uper && nums[lower] == target) {
            return new int[]{lower, uper};
        }  
        
        return new int[]{-1, -1};
    }
    
    public int findLowerBound(int[] nums, int target) {
        int start = 0, end = nums.length-1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] >= target) end = mid-1;
            else start = mid + 1;
        }
        return start;
    }
    
    public int findUperBound(int[] nums, int target) {
        int start = 0, end = nums.length-1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] > target) end = mid-1;
            else start = mid + 1;
        }
        return end;
    }
}