    public int removeDuplicates(int[] nums) {
        if (nums == null && nums.length == 0) return 0;
        
        int p = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                count = 1;
            } else {
                count ++;
            }
            
            if (count <= 2) {
                nums[p] = nums[i];
                p++;
            }
        }
        return p;
    }

    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int j = 2;
        for (int i = 2; i < n; ++i)
            if (A[i] != A[j-2])
                A[j++] = A[i];
        return j;
    }