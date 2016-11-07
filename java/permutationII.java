public class Solution {
     public void dfs(List<List<Integer>> ret, List<Integer> path, int[] nums, boolean[] visited) {
        if (path.size() == nums.length) {
            ret.add(new ArrayList<Integer>(path));
            return;
        }
        
        int lastIndex = -1;
        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                if (lastIndex != -1 && nums[lastIndex] == nums[i]) continue;
                path.add(nums[i]);
                visited[i] = true;
                dfs(ret, path, nums, visited);
                path.remove(path.size() - 1);
                visited[i] = false;
                lastIndex = i;
            }
        }
    }
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (nums.length == 0) return ret;
        
        Arrays.sort(nums);
        boolean[] visited = new boolean[nums.length];
        Arrays.fill(visited, false);
        dfs(ret, new ArrayList<Integer>(),  nums, visited);
        return ret;
        
    }
}