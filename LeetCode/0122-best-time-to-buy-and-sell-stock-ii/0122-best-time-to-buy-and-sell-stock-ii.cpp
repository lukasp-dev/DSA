class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        
        for(int i=0; i<prices.size()-1; i++){
            int curr = prices[i];
            int next = prices[i+1];

            if(curr < next){
                ret += next-curr;
            }
        }

        return ret;
    }
};