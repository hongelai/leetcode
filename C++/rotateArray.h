void rotateArray(vector<int> A, int k){
	reverse(A.begin(),A.end());
	reverse(A.begin(),A.begin()+k); //A.begin()+k is the end and will not be include
	reverse(A.begin()+k, A.end());
}

//how to check if  string S1 is the rotate of another string S2
//solution: find if S1 is in S2+S2(concatenate)

    //O(n) space
    void rotate(int nums[], int n, int k) {
        k = k%n;
        vector<int> vt(n,0);
        
        for (int i = 0; i < n; i++) {
            vt[i] = nums[(i+n-k)%n];
        }
        for (int i = 0; i < n; i++) nums[i] = vt[i];
    }

    //O(1) space
   	void reverse(int num[], int start, int end){
        while(start < end){
            swap(num[start++], num[end--]);
        }
    }
    void rotate(int nums[], int n, int k) {
        k = k%n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }