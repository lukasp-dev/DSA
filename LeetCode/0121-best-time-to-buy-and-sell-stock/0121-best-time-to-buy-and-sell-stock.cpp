class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int _min = prices[0];
        int ret = 0;

        for(int i=0; i<prices.size(); i++){
            _min = min(_min, prices[i]);
            ret = max(ret, prices[i] - _min);
        }

        return ret;
    }
};