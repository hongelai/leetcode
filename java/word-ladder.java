class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Queue<String> q = new LinkedList<>();
        HashSet<String> dict = new HashSet<>(wordList);
        HashSet<String> visited = new HashSet<>();
        int level = 1;
        
        q.offer(beginWord);
        dict.addAll(wordList);
        visited.add(beginWord);
        
        while(!q.isEmpty()) {
            for (int i = q.size(); i > 0; i--) {
                String word = q.poll();
                for (int j = 0; j < word.length(); j++) {
                    char[] next = word.toCharArray();
                    for (char c = 'a'; c <= 'z'; c++) {
                        next[j] = c;
                        String str = new String(next);
                        if (dict.contains(str) && !visited.contains(str)) {
                            if (str.equals(endWord)) return level + 1;
                            
                            q.offer(str);
                            visited.add(str);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
}