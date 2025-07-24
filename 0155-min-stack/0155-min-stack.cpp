class MinStack {
public:
    struct Node {
        int val;
        int currentMin;
    };

    stack<Node> stk;

    MinStack() {
        
    }
    
    void push(int val) {
        Node curr;
        curr.val = val;
        if(stk.empty()){
            curr.currentMin = val;
        }else{
            curr.currentMin = min(val, stk.top().currentMin);
        }
        stk.push(curr);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return (stk.top().val);
    }
    
    int getMin() {
        return (stk.top().currentMin);
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