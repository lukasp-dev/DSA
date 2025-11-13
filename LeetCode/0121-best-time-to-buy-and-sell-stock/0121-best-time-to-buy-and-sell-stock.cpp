class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int res = INT_MIN;

        for(int i=0; i<prices.size(); i++){
            res = max(res, prices[i] - minSoFar);
            minSoFar = min(minSoFar, prices[i]);
        }

        return res;
    }
};