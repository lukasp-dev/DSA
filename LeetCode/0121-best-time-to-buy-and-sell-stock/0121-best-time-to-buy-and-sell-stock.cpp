class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = -1;
        int minPrice = INT_MAX;
        for(int price : prices){
            minPrice = min(minPrice, price);
            res = max(res, price - minPrice);
        }

        return res;
    }
};