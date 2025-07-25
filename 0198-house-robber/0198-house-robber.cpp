class Solution {
public:
    int go(vector<int>& nums, vector<int>& memo, int n){
        if(n < 0) return 0;
        if(n == 0) return nums[0];
        if(n == 1) return max(nums[0], nums[1]);

        if(memo[n] != -1) return memo[n];

        return memo[n] = max(go(nums, memo, n - 1), nums[n] + go(nums, memo, n - 2));
    }

    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;

        int n = nums.size();
        vector<int> memo(n, -1);
        return go(nums, memo, n - 1);
    }
};
