class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> res = new ArrayList<>();
        
        long l = lower;
        for (int i = 0; i <= nums.length; i++) {
            long r = (i < nums.length && nums[i] <= upper) ? (long)nums[i] -1 : upper;
            if (r >= l) {
                res.add(r==l ? String.valueOf(l) : String.valueOf(l)+"->"+String.valueOf(r));
            }
            l = r+2;// r= nums[i]-1, r+2 = nums[i]+1 -> next range start
        }
        return res;
    }
}
