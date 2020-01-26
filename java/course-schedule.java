class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        LinkedList<Integer> q = new LinkedList<>();
        int[] in = new int[numCourses]; // 入度数量
        
        for (int[] dp : prerequisites) {
            ArrayList<Integer> list = map.getOrDefault(dp[0], new ArrayList<Integer>());
            list.add(dp[1]);
            map.put(dp[0], list);
            in[dp[1]]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.isEmpty()) { //delete edeges from nodes that has 0 indegree
            int course = q.poll();
            
            for (int c : map.getOrDefault(course, new ArrayList<Integer>())) {
                in[c]--;
                if (in[c] == 0) q.offer(c);
            }
        }
        
        // there is cycle if some nodes still has indegree
        for (int i = 0; i < numCourses; i++) {
            if (in[i] != 0)  return false;
        } 
        
        return true;
    }
}