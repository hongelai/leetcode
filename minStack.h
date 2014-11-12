struct node{
    int data;
    node* next;
};
class MinStack {              //memory space O(2n) memory limit exceed error

public:
    node* stackList;
    MinStack(){
        stackList = new node;
        stackList->next = NULL;
    }    
    void push(int x) {
        node* tmp = new node;
        if(tmp != NULL){
            tmp->data = x;
            tmp->next = stackList->next;
            stackList->next = tmp;

        }
    }

    void pop() {
        if(stackList->next != NULL){
            node* top = stackList->next;
            stackList->next = stackList->next->next;
            delete top;
        }
    }

    int top() {
        return stackList->next->data;
    }

    int getMin() {
        node* tmp = stackList->next;
        int minInt = stackList->next->data;
        while(tmp != NULL){
            if(tmp->data < minInt) minInt = tmp->data; 
            tmp = tmp->next;
        } 
        return minInt;
    }
};  


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


class MinStack {  //accepted
public:
    void push(int x) {
        s.push(x);
        if(mins.empty())
            mins.push(x);
        else{
            if(x <= mins.top())
                mins.push(x);
        }
    }

    void pop() {
        if(!s.empty()){  
            if(mins.top() == s.top())
                mins.pop();
            s.pop();
        }
    }

    int top() {

        return s.top();
    }

    int getMin() {
        return mins.top();
    }
    stack<int> s;
    stack<int> mins;
};