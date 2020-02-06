class Solution {
    public int findKthLargest(int[] nums, int k) {
        int low = 0, high = nums.length-1;

        
        while (true) {
            int p = partition(nums, low, high);
            if (p == k-1) return nums[p];
            if (p > k-1) high = p-1;
            else low = p+1;
        }
    }
    
    private int partition(int[] nums, int low, int high) {
        int pivot = nums[high];
        int index = low;
        
        for (int i = low; i < high; i++) {
            if (nums[i] >= pivot) {
                int tmp = nums[index];
                nums[index] = nums[i];
                nums[i] = tmp;
                index++;
            }
        }
        
        int tmp = nums[high];
        nums[high] = nums[index];
        nums[index] = tmp;
        
        return index;
    }
    
    private int partition(int[] a, int l, int h) {
        int i = l, j = h + 1;
        while (true) {
            while (a[++i] < a[l] && i < h) ;
            while (a[--j] > a[l] && j > l) ;
            if (i >= j) {
                break;
            }
            swap(a, i, j);
        }
        swap(a, l, j);
        return j;
    }
    
    private void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}
