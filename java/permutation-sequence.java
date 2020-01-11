class Solution {
    //https://leetcode.com/problems/permutation-sequence/discuss/22507/%22Explain-like-I'm-five%22-Java-Solution-in-O(n)
    public String getPermutation(int n, int k) {
        List<Integer> nums = new LinkedList<>();
        StringBuilder rs = new StringBuilder();
        int total = 1;
        
        for (int i = 1; i <= n; i++) {
            nums.add(i);
            total *= i;
        }
        
        k--;
        
        while (n > 0) {
            total /= n;
            int index = k / total;
            rs.append(nums.get(index));
            nums.remove(index);
            k -= index * total;
            n--;
        }
        
        return rs.toString();
    }
}