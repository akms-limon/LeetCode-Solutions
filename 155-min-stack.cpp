class MinStack {
    stack<long> s;
    long mn = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push(0);
            mn = val;
        }
        else s.push(mn - val);
        long x = val;
        mn = min(x, mn);
    }
    
    void pop() {
        if (s.top() >= 0) mn += s.top();
        s.pop();
    }
    
    int top() {
        if (s.top() < 0) return mn - s.top();
        else return (int)mn;
    }
    
    int getMin() {
        return (int)mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */