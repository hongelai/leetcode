public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        //k-SUM 的解法 先固定其中的k-2个值，剩下的2个值动态查找匹配的，最优解永远是O(n^k-2)
        Arrays.sort(nums);
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int start = i+1, end = nums.length-1;
            while (start < end) {
                if (nums[i] + nums[start] + nums[end] > 0) end--;
                else if (nums[i] + nums[start] + nums[end] < 0) start++;
                else {
                    ret.add(new ArrayList<Integer>(Arrays.asList(nums[i],nums[start++], nums[end--])));
                    while (start < end && nums[start] == nums[start-1]) start++;
                    while (start < end && nums[end] == nums[end+1]) end--;
                }
            }
        }
        return ret;
    }
}