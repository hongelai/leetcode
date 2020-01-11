class Solution {
    public int longestConsecutive(int[] nums) {
        int rs = 0;
        Set<Integer> set = new HashSet<Integer>();
        for (int i = 0 ; i < nums.length; i ++) {
            set.add(nums[i]);
        }
        
        for (int i = 0; i < nums.length ; i++) {
            if (set.contains(nums[i])) {
                int pre = nums[i], next = nums[i];

                while (set.contains(--pre)) {
                    set.remove(pre);
                }
        
                while(set.contains(++next)) {
                    set.remove(next);
                }
                rs = Math.max(rs, next - pre - 1);
            }
        }
        return rs;
    }
}