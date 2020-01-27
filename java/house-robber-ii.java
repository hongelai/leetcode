class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        
        return Math.max(rob(nums, 0 , nums.length-2), rob(nums, 1, nums.length-1));
    }
    
    private int rob(int[] nums, int start , int end) {
        int[] dp = new int[nums.length+1];
        
        for (int i = start; i <= end; i++) {
            dp[i] = Math.max(i-2 < 0 ? nums[i] : dp[i-2] + nums[i], i-1 < 0 ? 0: dp[i-1]);
        }
        
        return dp[end];
    }
}
