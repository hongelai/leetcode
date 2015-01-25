//find the first decrease digit from right to left
//find the first digit larger than the decreased digit
// swap these two
//reverse the right part
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        int index_d = size-2, index_c = size - 1;
        for(;index_d >= 0 && num[index_d] >= num[index_d+1]; index_d--);
        if(index_d != -1){
            for(; num[index_c] <= num[index_d]; index_c--);
            swap(num[index_d],num[index_c]);
        }
        reverse(num.begin()+index_d+1, num.end());
    }