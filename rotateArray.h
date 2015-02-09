void rotateArray(vector<int> A, int k){
	reverse(A.begin(),A.end());
	reverse(A.begin(),A.begin()+k); //A.begin()+k is the end and will not be include
	reverse(A.begin()+k, A.end());
}

//how to check if  string S1 is the rotate of another string S2
//solution: find if S1 is in S2+S2(concatenate)