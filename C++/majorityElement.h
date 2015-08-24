    int majorityElement(vector<int> &num) {
        return majorityElement_2(num);
    }
    //Moris voting algorithm
    int majorityElement_1(vector<int> &num){
        int candidate = -1;
        int count = 0;
        
        for(int i = 0; i < num.size(); i++){
            if(count == 0) {
                candidate = num[i];
                count = 1;
            } else {
                if (candidate == num[i]) count++;
                else count--;
            }
        }
        return candidate;
    }
    
    //count majority bits and form num
    int majorityElement_2(vector<int> &num){
        int size_int = sizeof(int)*8;
        int res = 0;
        
        for (int i = 0; i < size_int; i++) {
            int ones = 0, zeros = 0;
            for (int j = 0; j < num.size(); j++) {
                ((num[j] >>i) & 1) > 0 ? ones++ : zeros++; // 不能用(num[j] & (1<<i)) > 0判断i+1位是否为1, 100000000000可能是负数，返回负数
            }
            if (ones > zeros) res |= 1 << i;
        }
        return res;
    }