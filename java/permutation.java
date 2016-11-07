public class Solution {
    public  void dfs(List<List<Integer>> ret, List<Integer> path, int[] nums, boolean[] visited) {
        if (path.size() == nums.length) {
            ret.add(new ArrayList<Integer>(path));
            return;
        }
        
        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                path.add(nums[i]);
                visited[i] = true;
                dfs(ret, path, nums, visited);
                path.remove(path.size() - 1);
                visited[i] = false;
            }
        }
    }
    
    public  List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (nums.length == 0) return ret;
        boolean[] visited = new boolean[nums.length];
        Arrays.fill(visited, false);
        
        dfs(ret, new ArrayList<Integer>(),  nums, visited);
        
        return ret;
    }
}