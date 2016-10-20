public class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        
        Arrays.sort(candidates);
        backTracking(candidates, target, 0, new ArrayList<Integer>(), ret);
        return ret;
    }
    
    public void backTracking(int[] candidates, int target, int index, List<Integer> path, List<List<Integer>> ret) {
        if (target == 0) {
            ret.add(new ArrayList<Integer>(path));
            return;
        }
        for (int i = index; i < candidates.length && candidates[i] <= target; i++) {
            if (i != index && candidates[i-1] == candidates[i]) continue;
            path.add(candidates[i]);
            backTracking(candidates, target - candidates[i], i + 1, path, ret);
            path.remove(path.size()-1);
        }
    }
}