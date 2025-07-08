class CustomStack {
public:
    vector<int> stk;
    int n, maxSize; 

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        n = 0;
    }
    
    void push(int x) {
        if(n < maxSize){
            stk.push_back(x);
            n++;
        }
    }
    
    int pop() {
        if(n == 0) return -1;
        int ret = stk[n-1];
        n--;
        stk.erase(stk.end()-1, stk.end());
        return ret;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min(n, k); i++){
            stk[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */