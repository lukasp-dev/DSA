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

        int maxJmp = nums[index];
        int ans = INT_MAX;
        for(int i=1; i<=maxJmp; i++){
            int nextIndex = index + i;
            int sub = helper(nums, nextIndex, dp);
            if (sub != INT_MAX) { // overflow 방지
                ans = min(ans, 1 + sub);
            }
        }
        
        return dp[index] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return helper(nums, 0, dp);
    }
};