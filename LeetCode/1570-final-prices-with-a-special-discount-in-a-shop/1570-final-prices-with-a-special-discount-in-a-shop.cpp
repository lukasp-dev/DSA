class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> monotonic_stack;
        int n = prices.size();
        vector<int> ans(prices.begin(), prices.end());

        for (int i = 0; i < n; i++) {

            while (!monotonic_stack.empty() &&
                   prices[monotonic_stack.top()] >= prices[i]) {

                int index = monotonic_stack.top();
                monotonic_stack.pop();

                ans[index] = prices[index] - prices[i];
            }

            monotonic_stack.push(i);
        }

        return ans;
    }
};