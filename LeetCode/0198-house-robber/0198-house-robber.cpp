class Solution {
private:
    vector<int> memo;

    int dfs(vector<int>& nums, int start) {
        if(start >= nums.size()) return 0;

        if(memo[start] != -1) return memo[start];

        int skipThis = dfs(nums, start+1);
        int robThis = nums[start] + dfs(nums, start+2);

        return memo[start] = max(skipThis, robThis);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n+1, -1);

        return dfs(nums,0);
    }
};