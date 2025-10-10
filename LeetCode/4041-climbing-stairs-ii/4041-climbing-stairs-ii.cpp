typedef unsigned int ui;

ui getCost(int from, int to, vector<int>& costs){
    return (to-from)*(to-from) + costs[to-1];
}

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<ui> dp(n+1, 0);

        dp[1] = getCost(0, 1, costs);
        if(n==1) return dp[1];
        dp[2] = min(getCost(0, 2, costs), getCost(1, 2, costs) + dp[1]);
        if(n==2) return dp[2];
        dp[3] = min({getCost(0, 3, costs), getCost(1, 3, costs) + dp[1], getCost(2, 3, costs) + dp[2]});
        if(n==3) return dp[3];

        for(int i=4; i<n+1 ;i++){
            dp[i] = min({getCost(i-3, i, costs) + dp[i-3], getCost(i-2, i, costs) + dp[i-2], getCost(i-1, i, costs) + dp[i-1]});
        }

        return dp[n];
    }
};

