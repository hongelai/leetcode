class Solution {
    public int singleNumber(int[] nums) {
        int rs = 0;
            
        for (int i = 0; i < 32; i++) {
            int count = 0;
                
            for (int num : nums) {
                count += (num >> i) & 1;
            }
            rs |= (count % 3) << i;
        }
        
        return rs;
    }
}