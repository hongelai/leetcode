class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> levelWord = new HashSet<>(); //perisit word visited in current level
        HashSet<String> dict = new HashSet<>(wordList);
        List<List<String>> rs = new ArrayList<List<String>>();
        Queue<ArrayList<String>> paths = new LinkedList<ArrayList<String>>();
        int level = 1, minLevel = Integer.MAX_VALUE;
        paths.offer(new ArrayList<String>(Arrays.asList(beginWord)));
        
        while (!paths.isEmpty()) {
            ArrayList<String> path = paths.poll();
            
            if (path.size() > level) {
                //cannot reuse word visited in uper levels
                for (String s : levelWord) dict.remove(s);
                levelWord.clear();
                level = path.size();
                if (level >= minLevel) break;
            }
            
            String last = path.get(path.size() - 1);
            for (int i = 0; i < last.length(); i++) {
                char[] next = last.toCharArray();
                
                for (char c = 'a'; c <= 'z'; c++) {
                    next[i] = c;
                    String str = new String(next);
                    
                    if (dict.contains(str)) {
                        ArrayList<String> newPath = new ArrayList<>(path);
                        newPath.add(str);
                        if (str.equals(endWord)) {
                            rs.add(newPath);
                            minLevel = newPath.size();
                        } else {
                            paths.offer(newPath);
                        }
                        levelWord.add(str);
                    }
                }
            }
        }
        return rs;
    }
}
