class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;

        vector<int> maxSell(n, 0);

        int localMax = INT_MIN;

        for(int i=n-1; i>=0; i--){
            localMax = max(localMax, prices[i]);
            maxSell[i] = localMax;
        }

        int res = -1;
        int localMin = 1e9;

        for(int i=0; i<n-1; i++){
            localMin = min(localMin, prices[i]);
            res = max(res, maxSell[i+1] - localMin);
        }

        return res < 0 ? 0 : res;
    }
};