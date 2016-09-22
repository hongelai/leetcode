public class MinStack {

    /** initialize your data structure here. */
    public MinStack() {
        minSt = new Stack<Integer>();
        st = new Stack<Integer>();
    }
    
    public void push(int x) {
        st.push(x);
        if (minSt.isEmpty() || minSt.peek() >= x) minSt.push(x);
    }
    
    public void pop() {
        if (minSt.peek().equals(st.peek())) minSt.pop();
        st.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return minSt.peek();
    }
    Stack<Integer> minSt;
    Stack<Integer> st;
}

public class MinStack {

    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<Integer>();
        min = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        if (min >= x) {
            stack.push(min);//mark the previous min
            min = x;
        }
        stack.push(x);
    }
    
    public void pop() {
        if (!stack.isEmpty() && stack.pop().equals(min)) {
            min = stack.pop(); //set the previous min as current min
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return min;
    }
    
    Stack<Integer> stack;
    int min;
}