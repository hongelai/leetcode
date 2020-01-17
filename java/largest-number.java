class Solution {
    public String largestNumber(int[] nums) {
        String[] snums = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            snums[i] = String.valueOf(nums[i]);
        }
        
        Arrays.sort(snums, (s1, s2) -> (s2+s1).compareTo(s1+s2)); //O(knlogn) k-> average length of string
        StringBuilder rs = new StringBuilder();
        
        for (String s : snums) {
            rs.append(s);
        }
        
        if (rs.charAt(0) == '0') return "0";
        
        return rs.toString();
    }
}