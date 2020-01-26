class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if (nums.length == 0 || s == 0) return 0;
        
        int start = 0, end = 0, size = nums.length;
        int sum = 0, gap = Integer.MAX_VALUE;
        
        while (end < size) {
            while (sum < s && end < size) {
                sum += nums[end++];
                
            }
        
            while (sum >= s && start < size) {
                gap = Math.min(gap, end-start);
                sum -= nums[start++];
            }
        }
        
        return gap == Integer.MAX_VALUE ? 0 : gap;
    }
}
