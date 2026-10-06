class MinStack {
private:
    stack<pair<int, int>> minStack;

public:
    MinStack() {

    }
    
    void push(int value) {
        if(minStack.empty()) {
            minStack.push({value, value});
        } else {
            minStack.push({value, min(minStack.top().second, value)});
        }
    }
    
    void pop() {
        if(minStack.empty()) {
            throw runtime_error("Cannot pop from the empty stack.");
        } else {
            minStack.pop();
        }
    }
    
    int top() {
        if(minStack.empty()) {
            throw runtime_error("Cannot peek from the empty stack.");
        } else {
            return minStack.top().first;
        }
    }
    
    int getMin() {
        if(minStack.empty()) {
            throw runtime_error("Cannot get minimun from the empty stack.");
        } else {
            return minStack.top().second;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */