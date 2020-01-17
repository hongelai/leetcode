class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        long n = Math.abs((long)numerator), d = Math.abs((long)denominator);
        if (n == 0) return "0";
        
        HashMap<Long, Integer> map = new HashMap<>();
        StringBuilder rs = new StringBuilder();
        
        rs.append((numerator>0) ^ (denominator>0) ? "-" : "");
        rs.append(String.valueOf(n/d));
        n = n%d;
        if (n != 0) rs.append(".");
        
        while (n != 0) {
            if (map.containsKey(n)) {
                rs.insert(map.get(n), "(");
                rs.append(")");
                break;
            } else {
                map.put(n, rs.length());
                n = n*10;
                rs.append(String.valueOf(n/d));
                n = n%d;
                
            }
            
        }
        
        return rs.toString();
    }
}