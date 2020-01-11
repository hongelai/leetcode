class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        
        List<List<Integer>> rs = new ArrayList<List<Integer>>();
        if (nums.length < 4) return rs;
        
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.length; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int s = j + 1, e = nums.length - 1;
                while (s < e) {
                    int sum = nums[i] + nums[j] + nums[s] + nums[e];
                    if (sum > target) e--;
                    else if (sum < target) s++;
                    else {
                        rs.add(Arrays.asList(nums[i], nums[j], nums[s], nums[e]));
                        s++;
                        e--;
                        while (s < e && nums[s] == nums[s-1]) s++;
                        while (s < e && nums[e] == nums[e+1]) e--;
                    }
                }
            }
        }
        return rs;
    }
}