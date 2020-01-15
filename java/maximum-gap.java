class Solution {
    public int maximumGap(int[] nums) {
        int size = nums.length, res = 0, pre = 0;
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        if (size <= 1) return 0;
        
        for (int num : nums) {
            max = Math.max(max, num);
            min = Math.min(min, num);
        }
        
        int gap = (max-min)/size;
        int[] bucketMin = new int[size+1]; // +1 bucket to avoid array out of index
        int[] bucketMax = new int[size+1];
        Arrays.fill(bucketMin, Integer.MAX_VALUE);
        Arrays.fill(bucketMax, Integer.MIN_VALUE);
        
        for (int num : nums) {
            int id = (num-min)/(gap+1); // if nums is squential, gap will be less than 0, +1 to avoid gap == 0
            bucketMin[id] = Math.min(bucketMin[id], num);
            bucketMax[id] = Math.max(bucketMax[id], num);
        }
        
        for (int i = 1; i <= size; i++) {
          if(bucketMin[i] == Integer.MAX_VALUE || bucketMax[i] == Integer.MIN_VALUE) continue;
            res = Math.max(res, bucketMin[i] - bucketMax[pre]);
            pre = i;
        }
        
        return res;
    }
}