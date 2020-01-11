class Solution {
    public boolean search(int[] nums, int target) {
        if (nums == null || nums.length == 0) return false;
        
        int s = 0, e = nums.length - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > nums[s]) { //first half is sorted
                if (nums[s] <= target && nums[mid] > target) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else if (nums[mid] < nums[s]) { // second half is sorted
                if (nums[mid] < target && nums[e] >= target) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            } else{ // cannot determine if it is increasing or not  1 3 1 1 1 1 1
                s++;  //skip this duplicate
            }
        }
        return false;
    }
}