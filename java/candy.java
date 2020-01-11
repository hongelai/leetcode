class Solution {
    public int candy(int[] ratings) {
        int[] num =  new int[ratings.length];
        Arrays.fill(num, 1);
        
        for (int i = 0; i < ratings.length-1; i++) {
            if (ratings[i+1] > ratings[i]) {
                num[i+1]  = num[i] + 1;
            }
        }
        
        for (int i = ratings.length - 1; i > 0; i--) {
            if (ratings[i-1] > ratings[i]) {
                num[i-1] = Math.max(num[i-1], num[i] + 1);
            }
        }
        
        int sum = 0;
        for (int i : num) sum += i;
        
        return sum;
    }
}