class MinStack {                 //using one stack, store the difference
public:
    void push(int x) {
        if(s.empty()){
          
            min = x;
        }
        s.push(x - min);
        if(x < min) min = (long long)x;  // replace min after the push the min, so only whenever negative means min change
    }

    void pop() {
        if(!s.empty()){
            if(s.top() < 0) min = min - s.top();
            s.pop();
        }
    }

    int top() {
        if(s.top() < 0) return (int)min; // at turning point the min is itself
        else            return (int)(s.top()+min);
    }

    int getMin() {
        return (int)min;
    }
    stack<long long> s;
    long long min;
};


class MinStack {
public:
    void push(int x) {
        sk.push(x);
        if(minsk.empty() || x <= minsk.top()) minsk.push(x);
    }

    void pop() {
        if(!minsk.empty() && sk.top() == minsk.top()) minsk.pop();
        if(!sk.empty())sk.pop();        
    }

    int top() {
        return sk.top();
    }

    int getMin() {
        return minsk.top();
    }
    stack<int> minsk;
    stack<int> sk;  
};