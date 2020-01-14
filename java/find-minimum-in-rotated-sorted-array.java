class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        
        while (left+1 < right) { // left + 1避免各种边界，最后最多留两个比较
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) right = mid; //边界用mid就行，不用加1减1的，因为不用考虑边界问题了
            else left = mid;
        }
        return Math.min(nums[left], nums[right]);
    }
    
    public int findMin_1(int[] nums) {
        return findMin(nums, 0, nums.length-1);
    }
    
    private int findMin(int[] nums, int start, int end) {
        if (start >= nums.length) return Integer.MAX_VALUE;
        if (nums[start] <= nums[end]) return nums[start];
        
        int mid = (start + end) / 2;
        return Math.min(findMin(nums ,start, mid), findMin(nums, mid+1, end));
    }
}