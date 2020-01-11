class Solution {
    //hash same anagram together. use count to hash
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> dict = new HashMap<>();
        for (String str : strs) {
            String key = hash(str);
            dict.putIfAbsent(key, new ArrayList<String>());
            dict.get(key).add(str);
        }
        
        return new ArrayList(dict.values());
    }
    
    private String hash(String str) {
        int[] count = new int[26];
        for (int i = 0; i < str.length(); i++) {
            count[str.charAt(i) - 'a']++;
        }
        
        StringBuilder rs = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                rs.append(i);
                rs.append(count[i]);
                rs.append("#");
            }
        }
        return rs.toString();
    }
}