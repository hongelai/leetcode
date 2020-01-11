class Solution {
    //只要总和total大于0，就一定存在起点
    //只要阶段的sum小于0，从start开始到目前的节点都不可能是那个起点
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int size = gas.length;
        int total = 0, sum = 0, start = 0;
        
        for (int i = 0; i < size; i++) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            
            if (sum < 0) {
                start = i+1;
                sum = 0;
            }
        }
        
        return total < 0 ? -1 : start;
    }
    
    //O(n^2), 找一个剩余值一路相加都不小于0的起点
    public int canCompleteCircuit_2(int[] gas, int[] cost) {
        int size = gas.length;
        int[] remain = new int[size];
        
        int sum = 0;
        for (int i = 0; i < gas.length; i++) {
            remain[i] = gas[i] - cost[i];
            sum += remain[i];
        }
        
        if (sum < 0) return -1;
        
        for (int start = 0; start < size; start++) {
            if (remain[start] >= 0) {
                int total = 0;
                for (int i = 0; i < size; i++) {
                    total += remain[(start + i) % size];
                    if (total < 0) break;
                }
                if (total >= 0) return start;
            }
        }
        
        return -1;
    }
}