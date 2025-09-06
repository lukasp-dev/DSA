class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> minLeft;
        vector<int> maxRight(n, 0);
        int leftMin = prices[0];
        int rightMax = prices[n-1];

        for(int i=0; i<n; i++){
            leftMin = min(leftMin, prices[i]);
            minLeft.push_back(leftMin);
        }

        for(int i=n-1; i>=0; i--){
            rightMax = max(rightMax, prices[i]);
            maxRight[i] = rightMax;
        }

        int ret = 0;
        for(int i=0; i<n; i++){
            ret = max(ret, maxRight[i] - minLeft[i]);
        }

        return ret;
    }
};