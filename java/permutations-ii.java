class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        ArrayList<List<Integer>> rs = new ArrayList<List<Integer>>();
        if (nums == null || nums.length == 0) return rs;
        
        boolean[] visited = new boolean[nums.length];
        Arrays.sort(nums);
        backTracking(nums, visited, new ArrayList<Integer>(), rs);
        return rs;
    }
    
    private void backTracking(int[] nums, boolean[] visited, ArrayList<Integer> item, ArrayList<List<Integer>> rs) {
        if (item.size() == nums.length) {
            rs.add(new ArrayList<>(item));
            return;
        }
        
        int lastIndex = -1;
        for (int i = 0; i < nums.length; i++) {
            if (lastIndex != -1 && nums[lastIndex] == nums[i]) continue;
            if (!visited[i]) {
                item.add(nums[i]);
                visited[i] = true;
                backTracking(nums, visited, item, rs);
                item.remove(item.size() - 1);
                visited[i] = false;
                lastIndex = i;
            }
        }
    }
}