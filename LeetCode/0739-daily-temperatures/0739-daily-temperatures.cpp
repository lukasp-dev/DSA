class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> monotonic_stack;
        
        for(int i=0; i<n; i++) {
            while(!monotonic_stack.empty() &&
                temperatures[monotonic_stack.top()] < temperatures[i]) {
                    int top_idx = monotonic_stack.top();
                    monotonic_stack.pop();
                    ans[top_idx] = i - top_idx;
            }
            monotonic_stack.push(i);
        }
        return ans;
    }
};