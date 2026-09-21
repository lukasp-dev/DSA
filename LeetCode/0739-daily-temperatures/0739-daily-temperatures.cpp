class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> monotonic_stack;
        int n = temperatures.size();
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr_temp = temperatures[i];
            
            while(!monotonic_stack.empty() && 
                temperatures[monotonic_stack.top()] < curr_temp){
                int top_idx = monotonic_stack.top();
                monotonic_stack.pop();
                ans[top_idx] = i - top_idx;
            }
            monotonic_stack.push(i);
        }

        return ans;
    }
};