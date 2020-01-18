class Solution {
    public int countPrimes(int n) {
        boolean[] prime = new boolean[n];
        int count = 0;
        
        Arrays.fill(prime, true);
        
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
                //把倍数都变成false
                for (int j = 2; j * i < n; j++) prime[i*j] = false;
            }
        }
        
        return count;
    }
}
