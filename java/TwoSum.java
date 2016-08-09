public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer> ();
        
        for(int i = 0; i < nums.length; i++) {
            int wanted = target - nums[i];
            if(map.get(wanted) != null) {
                return new int[]{map.get(wanted), i};
            } else {
                map.put(nums[i], i);
            }
        }
        return null;
    }
}