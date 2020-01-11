class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
            int m = nums2.length;
            int left = (n + m + 1) / 2;
            int right = (n + m + 2) / 2;
            //将偶数和奇数的情况合并，如果是奇数，会求两次同样的 k 。
            return (findKthNumber(nums1, 0, n - 1, nums2, 0, m - 1, left) + findKthNumber(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;

    }
    
    public int findKthNumber(int[] nums1, int s1, int e1, int[] nums2, int s2, int e2, int k) {
            int l1 = e1 - s1 + 1;
            int l2 = e2 - s2 + 1;
            if (l1 > l2) return findKthNumber(nums2, s2, e2, nums1, s1, e1, k);
            if (l1 == 0) return nums2[s2+k-1];
            if (k == 1) return Math.min(nums1[s1], nums2[s2]);

            int i = s1 + Math.min(k/2, l1);
            int j = s2 + Math.min(k/2, l2);

            if (nums1[i-1] > nums2[j-1]){
                return findKthNumber(nums1, s1, e1, nums2, j, e2, k - (j-s2));
            } else {
                return findKthNumber(nums1, i, e1, nums2, s2, e2, k - (i-s1));
            }
        /*
            int i = s1 + Math.min(k/2, l1);
            int j = s2 + k - (i - s1);

            if (nums1[i-1] == nums2[j-1]) {
                return nums1[i-1];
            } else if (nums1[i-1] > nums2[j-1]){
                return findKthNumber(nums1, s1, e1, nums2, j, e2, k - (j-s2));
            } else {
                return findKthNumber(nums1, i, e1, nums2, s2, e2, k - (i-s1));
            }
        */
        }


    public double findKth(int[] A, int aStart, int[] B, int bStart, int k) {
        if (aStart > A.length - 1) return B[bStart + k - 1];
        if (bStart > B.length - 1) return A[aStart + k - 1];
        if (k == 1) return Math.min(A[aStart], B[bStart]);
        
        int aMid = Integer.MAX_VALUE, bMid = Integer.MAX_VALUE;
        if (aStart + k/2 - 1 < A.length) aMid = A[aStart + k/2 - 1];
        if (bStart + k/2 - 1 < B.length) bMid = B[bStart + k/2 - 1];
        
        if (aMid < bMid) {
            return findKth(A, aStart + k/2, B, bStart, k - k/2);
        } else {
            return findKth(A, aStart, B, bStart + k/2, k - k/2);
        }
    }


    //https://www.youtube.com/watch?v=LPFhl65R7ww
    public double findMedianSortedArrays(int[] A, int[] B) {
        if (A.length > B.length) { // make sure A is shorter to achieve log(min(m,n))
            int[] temp = A; A = B; B = temp;
        }
        int m = A.length, n = B.length;
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            
            if (i < iMax && B[j-1] > A[i]) { 
                //i is too small, do not move pointer if i is already rightmost
                iMin = i + 1;
            } else if (i > iMin && B[j] < A[i-1]) { 
                //i is too big, do not move pointer if i is already leftmost
                iMax = i - 1;
            } else {
                int maxLeft = 0;
                if (i == 0) maxLeft = B[j-1];
                else if (j == 0) maxLeft = A[i-1];
                else maxLeft = Math.max(A[i-1], B[j-1]);
                if ((m + n) % 2 == 1) return maxLeft;
                
                int minRight = 0;
                if (i == m) minRight = B[j];
                else if (j == n) minRight = A[i];
                else minRight = Math.min(A[i], B[j]);
                
                return (maxLeft + minRight) / 2.0;                          
            }                         
        } 
        return 0.0;
    }
    
}