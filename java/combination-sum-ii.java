class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> rs = new ArrayList<List<Integer>>();
        
        if (candidates == null || candidates.length == 0) return rs;
        
        Arrays.sort(candidates);
        backTracking(candidates, 0, target, new ArrayList<Integer>(), rs);
        
        return rs;
    }
    
    private void backTracking(int[] A, int index, int target, ArrayList<Integer> item, List<List<Integer>> rs) {
        
        if (target == 0) {
            rs.add(new ArrayList<>(item));
            return;
        }
        
        for (int i = index; i < A.length; i++) {
            if (A[i] > target) break;
            if (i > index && A[i] == A[i-1]) continue;
            
            item.add(A[i]);
            backTracking(A, i+1, target - A[i], item, rs);
            item.remove(item.size() - 1);
        }
    }
}