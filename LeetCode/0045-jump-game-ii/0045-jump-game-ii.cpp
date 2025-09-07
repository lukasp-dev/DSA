class Solution {
public:
    int helper(vector<int>& nums, int index, vector<int>& dp){
        int n = nums.size();
        if(index >= n-1){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }

        int maxJump = nums[index];
        int ans = 10001;
        for(int i=1; i<=maxJump; i++){
            int nextStep = index + i;
            if(nextStep < n){
                ans = min(ans, 1 + helper(nums, nextStep, dp));
            }
        }
        return dp[index] = ans;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, 0, dp);
    }
};