class Solution {
    //
    public int maxPoints(int[][] points) {
        int size = points.length;
        
        int res = 0;
        
        for (int i = 0; i < size; i++) {
            int samePoint = 0;
            int sameSlope = 0;
            HashMap<String, Integer> map = new HashMap<>();
       
            for (int j = i+1; j < size; j++) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    samePoint++;
                } else {
                    //double 0 和 -0 不相等，先把分子和分母通过最大公约数精简，然后用String 来表示斜率
                    int y = points[j][1] - points[i][1];
                    int x = points[j][0] - points[i][0];
                    int gcd = generateGcd(x, y);
                    x = x/gcd;
                    y = y/gcd;
                    String slope = String.valueOf(x) + ":" + String.valueOf(y);

                    
                    int count = map.getOrDefault(slope, 0);
                    map.put(slope, ++count);
                    sameSlope = Math.max(sameSlope, count);
                }
            }
            res = Math.max(res, samePoint+sameSlope+1);
        }
        
        return res;
    }
    
    //https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
     public int generateGcd(int x, int y) {
        if (y == 0) return x;
        return generateGcd(y, x % y);
    }
}