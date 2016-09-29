public class Solution {
    public void nextPermutation(int[] nums) {
        //find the first decrease digit from right to left
        //find the first digit larger than the decreased digit in right size
        // swap these two
        //reverse the right part
        int index_d = nums.length-2, index_l = nums.length-1;
        for (;index_d >= 0 && nums[index_d] >= nums[index_d+1]; index_d--);
        if (index_d >= 0) {
            for (;index_l > index_d && nums[index_l] <= nums[index_d]; index_l--);
            int tmp = nums[index_d];
            nums[index_d] = nums[index_l];
            nums[index_l] = tmp;
        }
        reverse(nums, index_d+1, nums.length-1);
    }
    public void reverse(int[] nums, int start, int end) {
        if (start >= end) return;
        while (start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
}