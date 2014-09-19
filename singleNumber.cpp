int singleNumber(int A[], int n) {
	int single = 0;
	for(int i = 0; i < n; i++)
		single ^= A[i];
	return single;
}
int singleNumber(int A[], int n) { //O(n2)
	
	for(int i = 0; i < n; i++)
		if(count(A,A+n,A[i]) < 2) 
			return single;
}