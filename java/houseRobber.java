public class Solution {
    public int rob(int[] nums) {
        int[] dp = new int[nums.length+1];
        Arrays.fill(dp, 0);
        if (nums.length >= 1) dp[1] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            dp[i+1] = Math.max(dp[i], dp[i-1] + nums[i]);
        }
        return dp[nums.length];
    }

    public int rob(int[] nums) {
        int preMax = 0, max = 0;
        if (nums.length >= 1) max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int tmpMax = max;
            max = Math.max(max, preMax + nums[i]);
            preMax = tmpMax;
        }
        return max;
    }
}