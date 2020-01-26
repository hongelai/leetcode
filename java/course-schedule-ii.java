class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        LinkedList<Integer> q = new LinkedList<>();
        ArrayList<Integer> res = new ArrayList<>();
        int[] in = new int[numCourses];
        
        for (int[] p : prerequisites) {
            ArrayList list = map.getOrDefault(p[0], new ArrayList<Integer>());
            list.add(p[1]);
            map.put(p[0], list);
            in[p[1]]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.isEmpty()) {
            int course = q.poll();
            res.add(course);
            
            for (int c : map.getOrDefault(course, new ArrayList<Integer>())) {
                in[c]--;
                if (in[c] == 0) {
                    q.offer(c);
                }
            }
        }
        
        if (res.size() == numCourses) {
            Collections.reverse(res);
        }
        
        return res.size() != numCourses ? new int[0] : res.stream().mapToInt(Integer::valueOf).toArray();
    }
}