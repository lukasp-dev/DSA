class Solution {
public:
    int go(vector<int>& memo, vector<int>& cost, int n){
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];

        if(memo[n] != -1) return memo[n];

        return memo[n] = cost[n] + min(go(memo, cost, n-1), go(memo, cost, n-2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(cost.size(), -1);

        return min(go(memo, cost, n-1), go(memo, cost, n-2));
    }
};