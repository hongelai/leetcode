class Solution {
    public int compareVersion(String version1, String version2) {
        List<Integer> v1 = getNumbers(version1);
        List<Integer> v2 = getNumbers(version2);
        int len = v1.size() > v2.size() ? v1.size() : v2.size();
        
        for (int i = 0; i < len; i ++) {
            int num1 = i < v1.size() ? v1.get(i) : 0;
            int num2 = i < v2.size() ? v2.get(i) : 0;
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
        }
        
        return 0;
    }
    
    private List<Integer> getNumbers(String s) {
        return Arrays.stream(s.split("\\."))
            .map(Integer::valueOf)
            .collect(Collectors.toList());
    }
}