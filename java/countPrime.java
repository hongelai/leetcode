int IsPrime(int number) {
    int i;
    for (i=2; i*i<=number; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}

public class Solution {
    public int countPrimes(int n) {
        //Sieve_of_Eratosthenes O(nloglogn)
        if (n <= 1) return 0;
        boolean[] prime = new boolean[n];
        Arrays.fill(prime, true);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
                for (int j = i+i; j < n; j+=i) prime[j] = false;
            }
        }
        return count;
    }
}