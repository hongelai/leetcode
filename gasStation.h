   //O(n2)
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

        vector<int> left;
        for(int i = 0; i < gas.size(); i++) left.push_back(gas[i] - cost[i]);
        int size = left.size();
        
        for(int index = 0; index < size; index++){
            if(left[index] < 0) continue;
            
            int sum = 0, i, j;
            for(i = index; i < size; i++){
                sum += left[i];
                if(sum < 0) break;
            }
            if( i == size){
                for(j = 0; j < index; j++){
                    sum += left[j];
                    if(sum < 0) break;
                }
                if(j == index) return index;
            }
        }
        return -1;
    }

    //optimal solution O(n)
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int j = -1;
        for (int i = 0, sum = 0; i < gas.size(); ++i) {
            //找到的点差值为正 并且可以使得余下的点 的和为正 且总和为正（总和为正意味着必有解）
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                j = i;
                sum = 0;
            }
        }
        return total >= 0 ? j + 1 : -1;
    }