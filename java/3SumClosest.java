public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int minGap = Integer.MAX_VALUE, minSum = Integer.MAX_VALUE;
        Arrays.sort(nums);
        
        for (int i = 0; i < nums.length-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int start = i+1, end = nums.length-1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                int gap = Math.abs(sum - target);
                if (gap < minGap) {
                    minSum = sum;
                    minGap = gap;
                }
                if (sum > target) end--;
                else if (sum < target) start++;
                else return sum;
            }
        }
        return minSum;
    }
}