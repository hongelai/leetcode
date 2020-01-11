class Solution {
    //Count the word in substring and words
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> rs = new ArrayList<>();
        Map<String, Integer> m1 = new HashMap<>();
        
        if (words == null || words.length == 0) {
            return rs;
        } 
        
        int m = words.length, n = words[0].length();
        
        for (String word : words) {
            m1.put(word, m1.getOrDefault(word, 0) + 1);
        }
        
        for (int i = 0; i <= s.length() - m * n; i++) {
            Map<String, Integer> m2 = new HashMap<>();
            int j = 0; // num of word
            for (; j < m; j++) {
                String word = s.substring(i + j * n, i + (j + 1) * n);
                if (!m1.containsKey(word)) break;
                m2.put(word, m2.getOrDefault(word, 0) + 1);
                
                if (m2.get(word) > m1.get(word)) break;
            }
            if (j == m) rs.add(i);
        }
        return rs;
    }
}