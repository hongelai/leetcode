    int trailingZeroes(int n) {
        //only 5*2 generate 10, we get enough 2 from even number,so we only count 5's, 10 has one 5, 25 has two 5s
        //https://oj.leetcode.com/discuss/19847/simple-c-c-solution-with-detailed-explaination
        return n==0? 0:n/5 + trailingZeroes(n/5);
    }