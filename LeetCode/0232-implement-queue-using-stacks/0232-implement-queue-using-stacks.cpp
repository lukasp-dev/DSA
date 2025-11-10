class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

public:
    MyQueue() {
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if(outStack.size() == 0){
            while(!inStack.empty()){
                outStack.push(inStack.top()); inStack.pop();
            }
        }
        int res = outStack.top();
        outStack.pop();
        return res;
    }
    
    int peek() {
        if(outStack.size() == 0){
            while(!inStack.empty()){
                outStack.push(inStack.top()); inStack.pop();
            }
        }
        return outStack.top();
    }
    
    bool empty() {
        return inStack.size() == 0 && outStack.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */