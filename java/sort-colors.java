class Solution {
    public void sortColors(int[] nums) {
        int one = 0, two = nums.length - 1;
        
        for (int i = 0; i <= two;) {
            if (nums[i] == 2) {
                int tmp = nums[i];
                nums[i] = nums[two];
                nums[two] = tmp;
                two--;
            } else if (nums[i] == 0) {
                int tmp = nums[i];
                nums[i] = nums[one];
                nums[one] = tmp;
                one++;
                i++;
            } else {
                i++;
            }
        }
    }
}