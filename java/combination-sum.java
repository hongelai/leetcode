class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> rs = new ArrayList<List<Integer>>();
        Arrays.sort(candidates);
        backtracking(candidates, 0, target, new ArrayList<Integer>(), rs);
        
        return rs;
    }
    
    private void backtracking(int[] A, int index, int target, ArrayList<Integer> item, List<List<Integer>> rs) {
        if (target == 0) {
            rs.add(new ArrayList<Integer>(item));
        }
        
        for (int i = index; i < A.length; i++) {
            if (A[i] > target) {
                break;
            } 
            else {
                item.add(A[i]);
                backtracking(A, i, target - A[i], item, rs);
                item.remove(item.size() - 1);
            }
        }   
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        // sort candidates to try them in asc order
        Arrays.sort(candidates); 
        // dp[t] stores all combinations that add up to t
        List<List<Integer>>[] dp = new ArrayList[target+1];
        
        
        // build up dp
        for(int t=0; t<=target; t++) {
            // initialize
            dp[t] = new ArrayList();
            // initialize
            List<List<Integer>> combList = new ArrayList();
            
            // for each t, find possible combinations
            for(int j=0; j<candidates.length && candidates[j] <= t; j++) {
                if(candidates[j] == t) {
                    combList.add(Arrays.asList(candidates[j])); // itself can form a list
                } else {
                    for(List<Integer> prevlist: dp[t-candidates[j]]) { // here use our dp definition
                        // i thought it makes more sense to compare with the last element
                        // only add to list when the candidates[j] >= the last element
                        // so the list remains ascending order, can prevent duplicate (ex. has [2 3 3], no [3 2 3])
                        // equal is needed since we can choose the same element many times   
                        if(candidates[j] >= prevlist.get(prevlist.size()-1)){
                            List temp = new ArrayList(prevlist); // temp is needed since 
                            temp.add(candidates[j]); // cannot edit prevlist inside 4eeach looop
                            combList.add(temp);
                        }
                    }
                }
            }
            dp[t] = combList;
        }
        return dp[target];
    } 
}