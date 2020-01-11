class Solution {
    //单调栈 https://www.cnblogs.com/grandyang/p/8887985.html
    public int largestRectangleArea(int[] heights) {
        if (heights == null || heights.length == 0) return 0;
        
        int rs = 0, N = heights.length;
        Stack<Integer> st = new Stack<>();
        
        for (int i = 0; i <= N; ) {
            int height = i == N ? 0 : heights[i]; 
            if (st.isEmpty()  || height > heights[st.peek()]) {
                st.push(i++);
            } else {
                int top = st.pop();
                int dist = st.isEmpty() ? i : i - st.peek() - 1; // -1 because we pop the highest one out already
                rs = Math.max(rs, heights[top] * dist);
            }
        }
        return rs;
    }
}