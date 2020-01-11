
    public static void findUnion(int[] a, int[] b) {
            int m = a.length, n = b.length;
            int i = 0, j = 0;
            List<Integer> res = new ArrayList<>();

            while (i < m && j < n) {
//                if (i > 0 && a[i] == a[i-1]) {
//                    i++;
//                    continue;
//                }
//                if (j > 0 && b[j] == b[j-1]) {
//                    j++;
//                    continue;
//                }

                if (a[i] < b[j]) {
                    res.add(a[i++]);
                } else if (a[i] > b[j]) {
                    res.add(b[j++]);
                } else {
                    res.add(a[i++]);
                    j++;
                }
            }

            while (i < m ) {
//                if (i > 0 && a[i] == a[i-1]) {
//                    i++;
//                    continue;
//                }
                res.add(a[i++]);
            }
            while (j < n) {
//                if (j > 0 && b[j] == b[j-1]) {
//                    j++;
//                    continue;
//                }
                res.add(b[j++]);
            }

            res.forEach(System.out::println);
    }

    public static void findUnionWithBinary(int A[], int B[]) {
            int pos = 0;
            for (int i = 0; i < A.length; i++) {
                // in order to count into duplicate, binarySearch need to find the first occurrence of target
                pos = binarySearch(B, pos, B.length, A[i]);
                if (pos == -1) {
                    System.out.println(A[i]);
                }
                pos ++;
            }
    }

    public static void findIntersectWithBinary(int A[], int B[]) {
            int pos = 0;
            for (int i = 0; i < A.length; i++) {
                pos = binarySearch(B, pos, B.length, A[i]);
                if (pos != -1) {
                    System.out.println(A[i]);
                }
                pos++;
            }
    }

    public static int binarySearch(int[] A, int l, int r, int target) {
            while (l <= r) {
                int mid = l + (r-l) / 2;

                if (A[mid] == target) {
                    if (mid - 1 >= l && A[mid] == A[mid -1]) { // always finds the first occurrence
                        r = mid - 1;
                    } else {
                        return mid;
                    }
                } else if (A[mid] > target) {
                    r = mid - 1 ;
                } else {
                    l = mid + 1;
                }

            }
            return -1;
    }
