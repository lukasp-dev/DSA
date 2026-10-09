class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        stack<int> mono_stack;
        for(int i=0; i<temperatures.size(); i++) {
            while(!mono_stack.empty() && temperatures[mono_stack.top()] < temperatures[i]) {
                int top_idx = mono_stack.top();
                mono_stack.pop();
                ans[top_idx] = i - top_idx;
            }
            mono_stack.push(i);
        }

        return ans;
    }
};