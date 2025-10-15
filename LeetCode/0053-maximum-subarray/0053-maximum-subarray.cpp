class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i=0; i<n; i++){
            sum += nums[i];
            if(nums[i] > sum) sum = nums[i];
            maxSum = max(maxSum, sum);
        }

        maxSum = max(maxSum, sum);

        return maxSum;
    }
};