class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        //find the common prefix between m and n, others bit will meet 0 and set to 0
        int mask = 0xFFFFFFFF;
        while ((m & mask) != (n & mask)) {
            mask <<= 1;
        }
        return m & mask;
    }
}
