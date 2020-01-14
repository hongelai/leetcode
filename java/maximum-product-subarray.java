class Solution {
    /*
     * minRes, maxRes 分别代表从0到i-1之间任意subarray的最小和最大值
     */
    public int maxProduct(int[] nums) {
        int minRes = nums[0], maxRes = nums[0], res = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int tmpMax = maxRes;
            maxRes = Math.max(nums[i], Math.max(minRes * nums[i], maxRes * nums[i]));
            minRes = Math.min(nums[i], Math.min(minRes * nums[i], tmpMax * nums[i]));
            res = Math.max(res, maxRes);
        }
        return res;
    }
}