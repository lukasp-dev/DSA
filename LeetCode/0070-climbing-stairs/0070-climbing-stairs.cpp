class Solution {
private:
    vector<int> memo;

    int dfs(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(memo[n] != -1) return memo[n];

        memo[n] = dfs(n-1) + dfs(n-2);
        return memo[n];
    }

public:
    int climbStairs(int n) {
        memo.assign(n + 1, -1);
        return dfs(n);
    } 
};