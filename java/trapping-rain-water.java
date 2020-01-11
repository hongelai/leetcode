class Solution {
    //Time: O(n^2)
    public int trap_1(int[] height) {
        int rs = 0;
        for (int i = 0; i < height.length; i++) {
            int maxLeft = 0, maxRight = 0;
            for (int l = i; l >= 0; l--) {
                maxLeft = Math.max(maxLeft, height[l]);
            }
            
            for (int r = i; r < height.length; r++) {
                maxRight = Math.max(maxRight, height[r]);
            }
            rs += Math.min(maxLeft, maxRight) - height[i];
        }
        
        return rs;
    }
    
    //Time: O(n), Space : O(n)
    public int trap_2(int[] height) {
        if (height == null || height.length == 0) return 0;
        
        int size = height.length, rs = 0;
        int[] maxLeft = new int[size], maxRight = new int[size];
        
        maxLeft[0] = height[0];
        for (int i = 1; i < size; i++) {
            maxLeft[i] = Math.max(height[i], maxLeft[i-1]);
        }
        
        maxRight[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            maxRight[i] = Math.max(height[i], maxRight[i+1]);
        }
        
        for (int i = 0; i < size; i++) {
            rs += Math.min(maxLeft[i], maxRight[i]) - height[i];
        }
        
        return rs;
    }
    
    public int trap(int[] height) {
        if (height == null || height.length == 0) return 0;
        int size = height.length, maxLeft = height[0], maxRight = height[size - 1];
        int s = 0, e = size - 1, rs = 0;
        
        while (s <= e) {
            if (height[s] < height[e]) {
                maxLeft = Math.max(maxLeft, height[s]);
                // always move the shorter one, so maxLeft < maxRight for sure.
                rs += Math.max(maxLeft, 0) - height[s];
                s++;
            } else {
                maxRight = Math.max(maxRight, height[e]);
                rs += Math.max(maxRight, 0) - height[e];
                e--;
            }
        }
        return rs;
    }
}