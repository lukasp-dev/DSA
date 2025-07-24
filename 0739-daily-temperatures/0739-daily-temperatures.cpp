class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        stk.push(0);
        vector<int> ret(temperatures.size());

        for(int i=1; i<temperatures.size(); i++){
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                ret[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ret;
    }
};
