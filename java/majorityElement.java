public class Solution {
    public int majorityElement(int[] nums) {
        //Moris voting
        int candidate = -1;
        int count = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (count == 0){
                candidate = nums[i];
                count++;
            } else {
                if (candidate == nums[i]) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return candidate;
    }
    
    public int majorityElement1(int[] nums) {
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            int ones = 0, zeros = 0;
            for (int j = 0; j < nums.length; j++) {
                if(((nums[j] >> i) & 1) > 0)  ones++;
                else zeros++;
            }
            if (ones > zeros) result |= 1<<i;
        }
        return result;
    }
}