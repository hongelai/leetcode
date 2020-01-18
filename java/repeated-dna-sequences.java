class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> rs = new ArrayList<>();
        if (s.length() <= 10) return rs;
        
        int index = 0;
        char[] array = s.toCharArray();
        HashMap<Integer, Integer> map = new HashMap<>();
        HashMap<Character, Integer> dict = new HashMap<>(){{
            put('A', 0);
            put('C', 1);
            put('G', 2);
            put('T', 3);
        }};
        int mask = 0xFFFFF, seq = 0; //used the first 20 bit
        
        while (index < 9) {
            seq = (seq << 2 & mask) | dict.get(s.charAt(index++));
        }
        while (index < array.length) {
            seq = (seq << 2 & mask) | dict.get(s.charAt(index++));
            
            if (map.containsKey(seq)) {
                if (map.get(seq) == 1) {
                    rs.add(new String(array, index-10, 10));
                }
                map.put(seq, map.get(seq)+1);
            } else {
                map.put(seq, 1);
            }
        }
        return rs;
    }
}