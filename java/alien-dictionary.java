class Solution {
    
    public String alienOrder(String[] words) {
        Map<Character, Set<Character>> map = new HashMap<>();
        Map<Character, Integer> degree = new HashMap<>();
        StringBuilder res = new StringBuilder();
        
        //init
        for (String word : words)
            for (char c : word.toCharArray()) {
                degree.put(c, 0);
            }
        
        //build graph
        for (int i = 0; i < words.length-1; i++) {
            char[] cur = words[i].toCharArray();
            char[] next = words[i+1].toCharArray();
            
            int len = Math.min(cur.length, next.length);
            for (int j = 0; j < len; j++) {
                char c1 = cur[j], c2 = next[j];
                
                if (c1 != c2) {
                    Set<Character> set = map.getOrDefault(c1, new HashSet<Character>());
                    
                    if (!set.contains(c2)) {
                        set.add(c2);
                        map.put(c1, set);
                        degree.put(c2, degree.get(c2)+1);
                    }
                    break;
                }
            }
        }
        
        Queue<Character> q = new LinkedList<>();
        degree.forEach((c, d) -> {
            if (d == 0) q.offer(c);
        });
        
        while (!q.isEmpty()) {
            char c = q.poll();
            degree.remove(c);
            res.append(c);
            
            Set<Character> set = map.getOrDefault(c, new HashSet<Character>());
            set.forEach(k -> {
                degree.put(k, degree.get(k)-1);
                if (degree.get(k) == 0) {
                    q.offer(k);
                }
            });
        }
        
        return degree.isEmpty() ? res.toString() : "";
    }

}
