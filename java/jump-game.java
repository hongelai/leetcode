class Solution {
    public boolean canJump_1(int[] nums) {
        if (nums == null || nums.length == 0) return false;
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            max = Math.max(max, nums[i] + i);
            if (max < i+1 && i+1 < nums.length) return false;
            if (max >= nums.length - 1) return true;
        }
        return false;
    }
    
    public boolean canJump(int[] nums) {
        if (nums == null || nums.length == 0) return false;
        int max = 0;
        for (int i = 0; i <= max && max < nums.length - 1; i++) {
            max = Math.max(max, nums[i] + i);
        }
        return max >= nums.length - 1;
    }
}