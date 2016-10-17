public class Solution {

    //plus one
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        Arrays.sort(candidates);
        if (candidates.length == 0) return ret;
        Map<Integer, List<List<Integer>>> map = new HashMap<Integer, List<List<Integer>>>();
        map.put(0, ret);
        for (int candidate : candidates) {
            for (int j = 1; j <= target; j++) {
                if (candidate <= j && map.containsKey(j - candidate)) {
                    List<List<Integer>> result = map.get(j);
                    if (result == null) result = new ArrayList<List<Integer>>();
                    if (j - candidate == 0) {
                        List<Integer> list = new ArrayList<>();
                        list.add(candidate);
                        result.add(list);
                    } else {
                        for (List<Integer> list : map.get(j - candidate)) {
                            ArrayList<Integer> newlist = new ArrayList<>(list);
                            newlist.add(candidate);
                            result.add(newlist);
                        }
                    }
                    map.put(j, result);
                }
            }
        }
        return map.get(target) != null ? map.get(target) : ret;
    }
    
    public List<List<Integer>> combinationSum1(int[] candidates, int target) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        Arrays.sort(candidates);
        dfs(candidates, target, 0, ret, new ArrayList<Integer>(), 0);
        return ret;
    }
    
    public void dfs(int[] candidates, int target, int index, List<List<Integer>> ret, List<Integer> item, int sum) {
        if (sum == target) {
            ArrayList<Integer> path = new ArrayList<>(item);
            ret.add(path);
            return;
        }
        
        for (int i = index; i < candidates.length && target >= candidates[i]; i++) {
            if(sum + candidates[i] > target) break;
            item.add(candidates[i]);
            dfs(candidates, target, i, ret, item, sum + candidates[i]);
            item.remove(item.size() - 1);
        }
    }
}