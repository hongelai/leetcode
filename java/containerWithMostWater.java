public class Solution {
    public int maxArea(int[] height) {
        int ret = Integer.MIN_VALUE;
        int left = 0, right = height.length-1;
        while (left < right) {
            ret = Math.max(ret, (right - left) * Math.min(height[left], height[right]));
            if (height[left] > height[right])  right--;
            else  left++;
        }
        return ret;
    }
}