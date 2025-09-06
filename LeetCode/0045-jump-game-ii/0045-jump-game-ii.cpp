class Solution {
public:
    int helper(vector<int>& nums, int index, vector<int>& dp){
        int n = nums.size();
        if(index >= n-1){
            return 0; // 이미 끝에 도달했으면 더 점프할 필요 없음
        }
        if(dp[index] != -1){
            return dp[index];
        }

        int maxJmp = nums[index];
        int ans = INT_MAX;

        for(int i=1; i<=maxJmp; i++){
            int nextIndex = index + i;
            int sub = helper(nums, nextIndex, dp);
            if (sub != INT_MAX) { // 도달 가능한 경우만
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