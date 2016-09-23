public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        for (int i = 1; i <= 32; i++) {
            if ((n & 1) > 0) count++;
            n = n >> 1;
        }
        return count;
    }
     //Brian Kernighan algonum
    public int hammingWeight(int n) {
        int count = 0;
        while(n != 0) {
            n &= n-1;
            count++;
        }
        return count;
    }
}