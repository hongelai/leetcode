class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0, right = nums.length-1;
        
        while (left + 1 < right) { 
            int mid = left + (right - left) / 2;

            // left + 1 < right 保证了进入到循环的区间起码有三个数以上
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if (nums[mid] > nums[mid-1]) left = mid;
            else right = mid;
        }
        
        return nums[left] > nums[right] ? left : right;
    }
}