class Solution {
public:
    int go(vector<int>& memo, int n){
        if(n == 0){
            return 1;
        }
        if(n == -1){
            return 0;
        }

        if(memo[n] != -1) return memo[n];

        return memo[n] = (go(memo, n-1) + go(memo, n-2));
    }

    int climbStairs(int n) {
        vector<int> memo(n+1, -1);
        return go(memo, n);
    }
};