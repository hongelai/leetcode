class Solution {
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) return -1;
        
        int m = nums.length;
        int s = 0, e = m-1;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[s] <= nums[mid]) { // first half is sorted
                if (target >= nums[s] && target < nums[mid]) { // check if target belongs to the sorted range
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else { // second half is sorted
                if (target > nums[mid] && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        
        return -1;
    }
}