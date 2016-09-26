public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (nums.length < 4) return ret;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length-3; i++) {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            for (int j = i + 1;  j < nums.length-2; j++) {
                if (j > i + 1 && nums[j-1] == nums[j]) continue;
                int start = j + 1, end = nums.length - 1;
                int need = target - nums[i] - nums[j];
                
                while (start < end) {
                    int sum = nums[start] + nums[end];
                    if (need > sum) {
                        start++;
                    } else if (need < sum) {
                        end--;
                    } else {
                        ret.add(new ArrayList<Integer>(Arrays.asList(nums[i], nums[j], nums[start++], nums[end--])));
                        while (start < end && nums[start-1] == nums[start]) start++;
                        while (start < end && nums[end+1] == nums[end]) end--;
                    }
                }
            }
        }
        return ret;
    }
}