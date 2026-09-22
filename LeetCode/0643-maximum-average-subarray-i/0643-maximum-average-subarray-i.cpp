class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long curr = 0;

        for (int i = 0; i < k; i++) {
            curr += nums[i];
        }

        long long maxSum = curr;

        for (int i = k; i < nums.size(); i++) {
            curr += nums[i] - nums[i - k];
            maxSum = max(maxSum, curr);
        }

        return static_cast<double>(maxSum) / k;
    }
};